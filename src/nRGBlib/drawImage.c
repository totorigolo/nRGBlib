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
    Color *pdata = img->data;
    Color c;
    unsigned int i, j;
    for (j = img->y; j < (img->y + img->h); j++)
    {
        for (i = img->x; i < (img->x + img->w); i++)
        {
            c = *pdata;
            //printf("%d ", c);
            setPixel(i, j, c, buffer);
            pdata += sizeof(Color);
        }
    }
}
