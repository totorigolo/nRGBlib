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

int main(int argc, char* argv[])
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Create the image
    Image image;
    ImageSubrect sub1, sub2;
    sub1.image = NULL;
    sub2.image = NULL;
    image.data = NULL;

    char path[] = "/documents/Examples/fond.h.tns";

    // Load the image
    loadImage(&image, path);

    // Init subrects
    setImage(&sub1, &image);
    sub1.offset_x = 30;
    sub1.offset_y = 20;
    sub1.w = 40;
    sub1.h = 40;

    setImage(&sub2, &image);
    sub2.x = 100;
    sub2.offset_x = 90;
    sub2.offset_y = 90;
    sub2.w = 100;
    sub2.h = 100;

    clearScreen(RGB(200, 200, 200), buffer);
    while (1)
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_ESC))
            break;

        if (isKeyPressed(KEY_NSPIRE_UP))
            sub1.y -= 2;
        if (isKeyPressed(KEY_NSPIRE_DOWN))
            sub1.y += 2;
        if (isKeyPressed(KEY_NSPIRE_LEFT))
            sub1.x -= 2;
        if (isKeyPressed(KEY_NSPIRE_RIGHT))
            sub1.x += 2;

        if (isKeyPressed(KEY_NSPIRE_8))
            sub2.y -= 2;
        if (isKeyPressed(KEY_NSPIRE_2))
            sub2.y += 2;
        if (isKeyPressed(KEY_NSPIRE_4))
            sub2.x -= 2;
        if (isKeyPressed(KEY_NSPIRE_6))
            sub2.x += 2;

        // Draw the image
        clearBuffer(RGB(200, 200, 200), buffer);

        drawImagesubrect(&sub2, buffer);
        drawImagesubrect(&sub1, buffer);

        // Display our buffer on the screen
        display(buffer);
    }

    // Delete our image
    deleteImage(&image);

    // Free our screen buffer
    free(buffer);

    // And quit
    return 0;
}
