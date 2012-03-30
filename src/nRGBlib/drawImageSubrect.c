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

/// Draw the image's subrect on the given buffer
void drawImagesubrect(ImageSubrect *imgsub, ScreenBuffer buffer)
{
    int i, j, jmax, width;

    if (!imgsub->image->data) return;

    // TODO: drawImageSubrect = memset for 4bpp
    if (!has_colors || !lcd_isincolor())
        for (i = ((imgsub->x < 0) ? (0) : (imgsub->x)); i < ((imgsub->x + imgsub->w >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (imgsub->x + imgsub->w)); i++)
            for (j = ((imgsub->y < 0) ? (0) : (imgsub->y)); j < ((imgsub->y + imgsub->h >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (imgsub->y + imgsub->h)); j++)
                setPixel(i, j, GET_SUBRECT_PIXEL(i - imgsub->x, j - imgsub->y, imgsub), buffer);
    else
    {
        i = (imgsub->x < 0) ? (0) : (imgsub->x);
        j = (imgsub->y < 0) ? (0) : (imgsub->y);
        jmax = ((imgsub->y + imgsub->h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (imgsub->y + imgsub->h);

        if (imgsub->x < 0)
            width = (0 + (imgsub->w - abs(imgsub->x)) >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (imgsub->w - abs(imgsub->x));
        else if (imgsub->x + imgsub->w >= SCREEN_WIDTH)
            width = SCREEN_WIDTH - imgsub->x;
        else
            width = imgsub->w;

        if (imgsub->x + imgsub->w < 0 || imgsub->x >= SCREEN_WIDTH)
            return;

        for (; j < jmax; j++)
            memcpy((((Color *)buffer) + (i + SCREEN_WIDTH * j)), &GET_SUBRECT_PIXEL(((imgsub->x < 0) ? (abs(imgsub->x)) : (0)), (j - imgsub->y), imgsub), width * 2);
    }
}
