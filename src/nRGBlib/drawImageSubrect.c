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
    int i, j;

    // Is the image loaded ?
    if (!imgsub->image->data)
    {
        printf("Can't draw unloaded images!\n");
        return;
    }

    for (i = ((imgsub->x < 0) ? (0) : (imgsub->x)); i < ((imgsub->x + imgsub->w >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (imgsub->x + imgsub->w)); i++)
        for (j = ((imgsub->y < 0) ? (0) : (imgsub->y)); j < ((imgsub->y + imgsub->h >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (imgsub->y + imgsub->h)); j++)
            setPixel(i, j, GET_SUBRECT_PIXEL(i - imgsub->x, j - imgsub->y, imgsub), buffer);

}


















