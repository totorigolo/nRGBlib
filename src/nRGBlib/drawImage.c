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
    int i, j, jmax, width;

    if (!img->data) return;

    // TODO: drawImage = memset for 4bpp
    if (!has_colors || !lcd_isincolor())
        for (i = ((img->x < 0) ? (0) : (img->x)); i < ((img->x + img->w >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (img->x + img->w)); i++)
            for (j = ((img->y < 0) ? (0) : (img->y)); j < ((img->y + img->h >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (img->y + img->h)); j++)
                setPixel(i, j, GET_IMG_PIXEL((i - img->x), (j - img->y), img), buffer);
    else
    {
        i = (img->x < 0) ? (0) : (img->x);
        j = (img->y < 0) ? (0) : (img->y);
        jmax = ((img->y + img->h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (img->y + img->h);

        if (img->x < 0)
            width = (0 + (img->w - abs(img->x)) >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (img->w - abs(img->x));
        else if (img->x + img->w >= SCREEN_WIDTH)
            width = SCREEN_WIDTH - img->x;
        else
            width = img->w;

        if (img->x + img->w < 0 || img->x >= SCREEN_WIDTH)
            return;

        for (; j < jmax; j++)
            memcpy((((Color *)buffer) + (i + (SCREEN_WIDTH * j))), &GET_IMG_PIXEL(((img->x < 0) ? (abs(img->x)) : (0)), (j - img->y), img), width * 2);
    }
}








