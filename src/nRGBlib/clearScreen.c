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

/// Clear screen with the selected color
void clearScreen(Color c, ScreenBuffer buffer[76800])
{
    // 4 bpp
    if (!has_colors || !lcd_isincolor())
    {
        memset(SCREEN_BASE_ADDRESS, (((getBW(c)) << 4) | getBW(c)), (SCREEN_WIDTH * SCREEN_HEIGHT / 2));
    }
    // 16 bpp
    else
    {
        unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        unsigned char *ptr;
        for (ptr = scr_base; ptr < scr_base + (SCREEN_WIDTH * SCREEN_HEIGHT * 2); ptr += sizeof(uint16_t))
            *(uint16_t*)ptr = c;

        if (buffer != NULL)
            memcpy(buffer, SCREEN_BASE_ADDRESS, SCREEN_BYTES_SIZE);
    }
}
