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
#include <nCOMMON.h>

/// Draw a pixel in color
void setPixel_s(int16_t x, int16_t y, Color c, ScreenBuffer buffer)
{
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;

    // 4 bpp
    else if (!has_colors || !lcd_isincolor())
    {
        unsigned char* p = (unsigned char*)(buffer + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | getBW(c)) : ((*p & 0x0F) | (getBW(c) << 4));
    }
    // 16 bpp
    else
    {
        *(((Color *)buffer) + (x + SCREEN_WIDTH * y)) = c;
    }
}
void setPixel(int16_t x, int16_t y, Color c, ScreenBuffer buffer)
{
    // 4 bpp
    if (!has_colors || !lcd_isincolor())
    {
        unsigned char* p = (unsigned char*)(buffer + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | getBW(c)) : ((*p & 0x0F) | (getBW(c) << 4));
    }
    // 16 bpp
    else
    {
        *(((Color *)buffer) + (x + SCREEN_WIDTH * y)) = c;
    }
}
