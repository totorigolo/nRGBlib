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

#include <nCOMMON.h>
#include <os.h>

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Draw a pixel in color
void setPixel(int16_t x, int16_t y, Color c, ScreenBuffer buffer[76800])
{
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;

    // 4 bpp
    if (!has_colors || !lcd_isincolor())
    {
        unsigned char* p = (unsigned char*)(SCREEN_BASE_ADDRESS + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | getBW(c)) : ((*p & 0x0F) | (getBW(c) << 4));
    }
    // 16 bpp
    else
    {
        /*unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        unsigned char *ptr;
        ptr = scr_base + sizeof(uint16_t) * (x + SCREEN_WIDTH * y);
        *(unsigned short*)ptr = c;*/
        buffer[x + SCREEN_WIDTH * y] = c;
    }
}
