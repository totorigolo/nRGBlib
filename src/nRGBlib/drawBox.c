/****************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The Original Code is nRGBlib code.
 *
 * The Initial Developer of the Original Code is Thomas LACROIX aka totorigolo
 * <toto.rigolo@free.fr>.
 * Portions created by the Initial Developer are Copyright (C) 2011-2012
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 ****************************************************************************/

#include <os.h>
#include <nGEO.h>

/// Draw a box / rectangle in color
void drawBox_(int16_t x, int16_t y, int16_t w, int16_t h, Color c, ScreenBuffer buffer)
{
    int i, j, jmax, width, k, special = 0;
    uint8_t cc = getBW(c);
    void *tmpc;

    if (!has_colors || !lcd_isincolor())
    {
        // If the box is out of screen, return
        if ((x / 2) + (w / 2) < 0 || (x / 2) >= (SCREEN_WIDTH / 2))
            return;

        i = (x < 0) ? (0) : (x / 2);
        j = (y < 0) ? (0) : (y);
        jmax = ((y + h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (y + h);

        // Calculate the box's width
        if ((x / 2) < 0)
            width = (0 + ((w / 2) - abs((x / 2))) >= SCREEN_WIDTH / 2) ? (SCREEN_WIDTH / 2) : ((w / 2) - abs((x / 2)));
        else if ((x / 2) + (w / 2) >= SCREEN_WIDTH / 2)
            width = (SCREEN_WIDTH / 2) - (x / 2);
        else
            width = (w / 2);

        // Check if the box as even coords
        //if (!(x & 1) && !(w & 1));
        if (x & 1 && w & 1)
        {
            special = 1;
            width += 1;
        }
        else if (!(x & 1) && w & 1)
        {
            special = 2;
            width += 1;
        }
        else if (x & 1 && !(w & 1))
        {
            special = 3;
            width += 1;
        }

        // Malloc the box to draw
        tmpc = (uint8_t*)malloc((width) * sizeof(uint8_t));

        // Fill the temporary line
        for (k = 0; k < width; k++)
            *(uint8_t*)(tmpc + (k * sizeof(uint8_t))) = (cc << 4) | cc;

        // Draw in the buffer
        for (; j < jmax; j++)
        {
            // Delete pixels
            if (special == 1 || special == 3)
                *(uint8_t*)tmpc = ((*(uint8_t*)(buffer + ((i + ((SCREEN_WIDTH / 2) * j)) * sizeof(uint8_t)))) & 0xF0) | cc;
            if (special == 2 || special == 3)
                *(uint8_t*)(tmpc + (width-1) * sizeof(uint8_t)) = (cc << 4) | (*(uint8_t*)(buffer + ((i + (width-1) + ((SCREEN_WIDTH / 2) * j)) * sizeof(uint8_t)))) & 0x0F;

            memcpy((uint8_t*)(buffer + ((i + ((SCREEN_WIDTH / 2) * j)) * sizeof(uint8_t))), (uint8_t*)tmpc, width);
        }
    }
    else
    {
        if (x + w < 0 || x >= SCREEN_WIDTH)
            return;

        i = (x < 0) ? (0) : (x);
        j = (y < 0) ? (0) : (y);
        jmax = ((y + h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (y + h);

        if (x < 0)
            width = (0 + (w - abs(x)) >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (w - abs(x));
        else if (x + w >= SCREEN_WIDTH)
            width = SCREEN_WIDTH - x;
        else
            width = w;
        width *= 2;

        tmpc = (Color*)malloc(width * sizeof(Color));
        for (k = 0; k < width; k++)
            *(Color*)(tmpc + k * sizeof(Color)) = c;

        for (; j < jmax; j++)
            memcpy((Color*)(buffer + ((i + (SCREEN_WIDTH * j)) * sizeof(Color))), (Color*)tmpc, width);
    }
    free(tmpc);
}
inline void drawBox(Box *box, Color c, ScreenBuffer buffer)
{
    drawBox_(box->x, box->y, box->w, box->h, c, buffer);
}

/// Draw a square in color
inline void drawSquare_(int16_t x, int16_t y, int16_t side, Color c, ScreenBuffer buffer)
{
    drawBox_(x, y, side, side, c, buffer);
}
inline void drawSquare(Square *s, Color c, ScreenBuffer buffer)
{
    drawBox_(s->x, s->y, s->side, s->side, c, buffer);
}
