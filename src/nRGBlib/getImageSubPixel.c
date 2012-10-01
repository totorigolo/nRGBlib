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

/// Get a pixel from any image subrect
void* getImageSubPixel(uint16_t x, uint16_t y, ImageSubrect *sub)
{
    if (!has_colors || !lcd_isincolor())
        return getImageSubPixel_4bpp(x, y, sub);

    else
        return getImageSubPixel_16bpp(x, y, sub);
}

/// Get a pixel from a 4bpp image subrect
void* getImageSubPixel_4bpp(uint16_t x, uint16_t y, ImageSubrect *sub)
{
    return getImagePixel_4bpp(x + sub->offset_x, (y + sub->offset_y), sub->image);
}

/// Get a pixel from a 16bpp image subrect
void* getImageSubPixel_16bpp(uint16_t x, uint16_t y, ImageSubrect *sub)
{
    return getImagePixel_16bpp((x + sub->offset_x), (y + sub->offset_y), sub->image);
}
