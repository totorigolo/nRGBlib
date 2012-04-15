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
    int i, j, jmax, width, x;

    if (!imgsub->image->data) return;

    if (!has_colors || !lcd_isincolor())
    {
        if (imgsub->x / 2 + (imgsub->w / 2) < 0 || imgsub->x / 2 >= SCREEN_WIDTH / 2)
            return;

        i = (imgsub->x < 0) ? (0) : (imgsub->x / 2);
        j = (imgsub->y < 0) ? (0) : (imgsub->y);
        x = ((imgsub->x < 0) ? (abs(imgsub->x)) : (0));
        jmax = ((imgsub->y + imgsub->h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (imgsub->y + imgsub->h);

        if (imgsub->x / 2 < 0)
            width = (0 + ((imgsub->w / 2) - abs(imgsub->x / 2)) >= SCREEN_WIDTH / 2) ? (SCREEN_WIDTH / 2) : ((imgsub->w / 2) - abs(imgsub->x / 2));
        else if (imgsub->x / 2 + imgsub->w / 2 >= SCREEN_WIDTH / 2)
            width = (SCREEN_WIDTH / 2) - imgsub->x / 2;
        else
            width = imgsub->w / 2;

        for (; j < jmax; j++)
            memcpy((uint8_t*)(buffer + ((i + (SCREEN_WIDTH / 2 * j)) * sizeof(uint8_t))), getImageSubPixel_4bpp(x, (j - imgsub->y), imgsub), width);
    }
    else
    {
        if (imgsub->x + imgsub->w < 0 || imgsub->x >= SCREEN_WIDTH)
            return;

        i = (imgsub->x < 0) ? (0) : (imgsub->x);
        j = (imgsub->y < 0) ? (0) : (imgsub->y);
        x = ((imgsub->x < 0) ? (abs(imgsub->x)) : (0));
        jmax = ((imgsub->y + imgsub->h) >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (imgsub->y + imgsub->h);

        if (imgsub->x < 0)
            width = (0 + (imgsub->w - abs(imgsub->x)) >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (imgsub->w - abs(imgsub->x));
        else if (imgsub->x + imgsub->w >= SCREEN_WIDTH)
            width = SCREEN_WIDTH - imgsub->x;
        else
            width = imgsub->w;
        width *= 2;

        for (; j < jmax; j++)
            memcpy((Color *)(buffer + ((i + (SCREEN_WIDTH * j)) * sizeof(Color))), getImageSubPixel_16bpp(x, (j - imgsub->y), imgsub), width);
    }
}
