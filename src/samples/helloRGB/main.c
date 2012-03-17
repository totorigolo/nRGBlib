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
#include <nGEO.h>
#include <nGUI.h>

/** Two rendering methods exist:
    - direct rendering
    - double buffering rendering
    Change the following define to try both methods */
#define DIRECT_RENDERING 0

int main()
{
#if DIRECT_RENDERING == 0
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();
#else
    // Get the direct rendering buffer
    ScreenBuffer buffer = GetDirectScreenBuffer();
#endif

    // Create a new color
    Color c1 = RGB(233, 0, 128); // Purple-gray

    // Two deffierents ways to create a line
    Line l1 = { SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5, SCREEN_WIDTH / 2 + CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5 };
    Line l2 = { .x1 = 76, .x2 = 244, .y1 = 140, .y2 = 140 };

#if DIRECT_RENDERING == 0
    // Copy current screen's pixels to our buffer
    copyScreenToBuffer(buffer);
#endif

    // Draw everything
    drawStr(SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 - CHAR_HEIGHT / 2, "Hello !", 2, 0, RGB(50, 205, 50), buffer); // Verdâtre
    drawLine(&l1, c1, buffer);
    drawLine(&l2, RED, buffer);

    // Display our buffer on the screen
    display(buffer);

    // Wait
    while (any_key_pressed());
    while (!any_key_pressed())
        sleep(100);

#if DIRECT_RENDERING == 0
    // Free our screen buffer -> Don't forget !!!
    free(buffer);
#else
    // Forget the buffer
    buffer = NULL;
#endif

    // And quit
    return 0;
}
