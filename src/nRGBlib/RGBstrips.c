/****************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The Original Code is nRGBlib code.
 *
 * The Initial Developer of the Original Code is Thomas LACROIX aka totorigolo
 * <toto.rigolo@free.fr>.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 ****************************************************************************/

#include <nGEO.h>
#include <os.h>

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Draw three red, green and blue strips
void RGBstrips()
{
    // 4 bpp
#if (__FAST_SETPIXEL__ == 1) // nCOMMON.h
    if (!has_colors)
#else
    if (!has_colors || ((*IO_LCD_CONTROL & 0b1110) != 0b1100)) // R5G6B5 - libndls - lcd_isincolor())
#endif
    {
        // TODO: RGBstrips pour non-CX
    }
    // 16 bpp
    else
    {
        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr;

        for (ptr = scr_base; ptr < scr_base + SCREEN_BYTES_SIZE / 3; ptr += 2)
            *(volatile unsigned short*)ptr = 0b1111100000000000;

        for (; ptr < scr_base + SCREEN_BYTES_SIZE * 2 / 3; ptr += 2)
            *(volatile unsigned short*)ptr = 0b0000011111100000;

        for (; ptr < scr_base + SCREEN_BYTES_SIZE; ptr += 2)
            *(volatile unsigned short*)ptr = 0b0000000000011111;
        }
}
