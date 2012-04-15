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
#include <nIMAGE.h>

/// Draw the image on the given buffer
void drawImage(Image *img, ScreenBuffer buffer)
{
    int i, j, jmax, width, x;

    if (!img->data) return;

    if (!has_colors || !lcd_isincolor())
    {
        if (img->x / 2 + img->w / 2 < 0 || img->x / 2 >= SCREEN_WIDTH / 2)
            return;

        i = (img->x < 0) ? (0) : (img->x / 2);
        j = (img->y < 0) ? (0) : (img->y);
        x = ((img->x < 0) ? (abs(img->x)) : (0));
        jmax = ((img->y + img->h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (img->y + img->h);

        if (img->x / 2 < 0)
            width = (0 + ((img->w / 2) - abs(img->x / 2)) >= SCREEN_WIDTH / 2) ? (SCREEN_WIDTH / 2) : ((img->w / 2) - abs(img->x / 2));
        else if (img->x / 2 + img->w / 2 >= SCREEN_WIDTH / 2)
            width = (SCREEN_WIDTH / 2) - img->x / 2;
        else
            width = img->w / 2;

        for (; j < jmax; j++)
            memcpy((uint8_t*)(buffer + ((i + (SCREEN_WIDTH / 2 * j)) * sizeof(uint8_t))), getImagePixel_4bpp(x, (j - img->y), img), width);
    }
    else
    {
        if (img->x + img->w < 0 || img->x >= SCREEN_WIDTH)
            return;

        i = (img->x < 0) ? (0) : (img->x);
        j = (img->y < 0) ? (0) : (img->y);
        x = ((img->x < 0) ? (abs(img->x)) : (0));
        jmax = ((img->y + img->h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (img->y + img->h);

        if (img->x < 0)
            width = (0 + (img->w - abs(img->x)) >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (img->w - abs(img->x));
        else if (img->x + img->w >= SCREEN_WIDTH)
            width = SCREEN_WIDTH - img->x;
        else
            width = img->w;
        width *= 2;

        for (; j < jmax; j++)
            memcpy((Color *)(buffer + ((i + (SCREEN_WIDTH * j)) * sizeof(Color))), getImagePixel_16bpp(x, (j - img->y), img), width);
    }
}
