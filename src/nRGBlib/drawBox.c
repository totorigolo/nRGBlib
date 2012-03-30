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
    int i, j, jmax, width, k;
    Color *tmpc;

    // TODO: drawBox = memset for 4bpp
    if (!has_colors || !lcd_isincolor())
        for (i = ((x < 0) ? (0) : (x)); i < ((x + w >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (x + w)); i++)
            for (j = ((y < 0) ? (0) : (y)); j < ((y + h >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (y + h)); j++)
                setPixel(i, j, c, buffer);
    else
    {
        i = (x < 0) ? (0) : (x);
        j = (y < 0) ? (0) : (y);
        jmax = ((y + h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (y + h);

        if (x < 0)
            width = (0 + (w - abs(x)) >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (w - abs(x));
        else if (x + w >= SCREEN_WIDTH)
            width = SCREEN_WIDTH - x;
        else
            width = w;

        if (x + w < 0 || x >= SCREEN_WIDTH)
            return;

        tmpc = calloc(width, sizeof(Color));
        for (k = 0; k < width; k++)
            tmpc[k] = c;

        for (; j < jmax; j++)
            memcpy((((Color *)buffer) + (i + SCREEN_WIDTH * j)), tmpc, width * 2);

        free(tmpc);
    }
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
