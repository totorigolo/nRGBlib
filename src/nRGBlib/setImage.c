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

/// Set the ImageSubrect's image
void setImage(ImageSubrect *imgsub, Image *img)
{
    imgsub->w = 0;
    imgsub->h = 0;
    imgsub->offset_x = 0;
    imgsub->offset_y = 0;

    if (imgsub->image == NULL)
    {
        imgsub->x = 0;
        imgsub->y = 0;
    }

    imgsub->image = img;
}
