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
#include <nGEO.h>
#include <os.h>

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Display the buffer on the screen
void copyScreenToBuffer(ScreenBuffer buffer[76800])
{
    // 4 bpp
    if (!has_colors || !lcd_isincolor());
    // 16 bpp
    else
    {
        memcpy(buffer, SCREEN_BASE_ADDRESS, SCREEN_BYTES_SIZE);
    }
}
