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

/// Get a pixel from any image
inline void* getImagePixel(uint16_t x, uint16_t y, Image *img)
{
    if (!has_colors || !lcd_isincolor())
        return (uint8_t*)(img->data + (x + (y * (img->w / 2)) * sizeof(uint8_t)));

    else
        return (Color*)(img->data + ((x + (y * img->w)) * sizeof(Color)));
}

/// Get a pixel from a 4bpp image
inline void* getImagePixel_4bpp(uint16_t x, uint16_t y, Image *img)
{
    return (uint8_t*)(img->data + (x + (y * (img->w / 2)) * sizeof(uint8_t)));
}

/// Get a pixel from a 16bpp image
inline void* getImagePixel_16bpp(uint16_t x, uint16_t y, Image *img)
{
    return (Color*)(img->data + ((x + (y * img->w)) * sizeof(Color)));
}
