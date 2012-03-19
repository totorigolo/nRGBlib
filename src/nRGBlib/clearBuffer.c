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

/// Clear buffer with the selected color
void clearBuffer(Color c, ScreenBuffer buffer)
{
    if (buffer == NULL) return;

    unsigned int x, y;
    for (x = 0; x < SCREEN_WIDTH; x++)
        for (y = 0; y < SCREEN_HEIGHT; y++)
            *(((Color *)buffer) + (x + SCREEN_WIDTH * y)) = c;
}
