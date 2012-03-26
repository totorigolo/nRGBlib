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
    int i, j;

    // Is the image loaded ?
    if (!img->data) return;

/*
    // TODO: memcpy (drawImages.h)
    for (i = ((img->x < 0) ? (0) : (img->x)); i < ((img->x + img->w >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (img->x + img->w)); i++)
        memcpy((((Color *)buffer) + (i + SCREEN_WIDTH * img->y)), &GET_IMG_PIXEL((i - img->x), 0, img), ((img->y + img->h >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (img->y + img->h)) * 2);

*/
    for (i = ((img->x < 0) ? (0) : (img->x)); i < ((img->x + img->w >= SCREEN_WIDTH) ? (SCREEN_WIDTH) : (img->x + img->w)); i++)
        for (j = ((img->y < 0) ? (0) : (img->y)); j < ((img->y + img->h >= SCREEN_HEIGHT) ? (SCREEN_HEIGHT) : (img->y + img->h)); j++)
            setPixel(i, j, GET_IMG_PIXEL((i - img->x), (j - img->y), img), buffer);
}
