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

/// Clear screen with the selected color
void clearScreen(Color c, ScreenBuffer buffer)
{
    // 4 bpp
    if (!has_colors || !lcd_isincolor())
    {
        // Clear the screen the color
        memset(SCREEN_BASE_ADDRESS, (((getBW(c)) << 4) | getBW(c)), (SCREEN_WIDTH * SCREEN_HEIGHT / 2));

        // Copy the screen buffer to the given buffer
        if (buffer != NULL)
            memcpy(buffer, SCREEN_BASE_ADDRESS, SCREEN_BYTES_SIZE);
    }
    // 16 bpp
    else
    {
        // Clear the screen with the color
        unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        unsigned char *ptr;
        for (ptr = scr_base; ptr < scr_base + (SCREEN_WIDTH * SCREEN_HEIGHT * 2); ptr += sizeof(uint16_t))
            *(uint16_t*)ptr = c;

        // Copy the screen buffer to the given buffer
        if (buffer != NULL)
            memcpy(buffer, SCREEN_BASE_ADDRESS, SCREEN_BYTES_SIZE);
    }
}
