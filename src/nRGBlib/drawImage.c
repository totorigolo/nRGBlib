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
    Color c;
    int i, j;

    // Is the image loaded ?
    if (!img->data) return;

    for (i = img->x; i < (img->x + img->w); i++)
    {
        if (i > SCREEN_WIDTH) break;
        if (i < 0) continue;
        for (j = img->y; j < (img->y + img->h); j++)
        {
            if (j > SCREEN_HEIGHT) break;
            if (j < 0) continue;
            setPixel(i, j, GET_IMG_PIXEL((i - img->x), (j - img->y), img), buffer);
        }
    }
}
