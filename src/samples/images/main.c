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
#include <nGUI.h>

int main(int argc, char* argv[])
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Create the image
    int speed = 2;
    Image image;
    image.data = NULL;

// TODO: Explorateur de fichiers (sample/images)

    // Find the image path
    /*char *file = "elephant.h.tns";
    int len = strrchr(argv[0], '/') - argv[0] + 1;
    char path[len + strlen(file) + 1];
    memcpy(path, argv[0], len);
    memcpy(path + len * sizeof(char), file, strlen(file));*/

    char path[] = "/documents/Examples/bac.h.tns";
    //char path[] = "/documents/ndless/dev/bac.h.tns";

    // Load the image
    loadImage(&image, path);

    clearScreen(RGB(200, 200, 200), buffer);
    while (1)
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_ESC))
            break;

        // Up and down
        if (isKeyPressed(KEY_NSPIRE_UP) || isKeyPressed(KEY_NSPIRE_8))
            image.y -= speed;
        if (isKeyPressed(KEY_NSPIRE_DOWN) || isKeyPressed(KEY_NSPIRE_2))
            image.y += speed;

        // Left and right
        if (isKeyPressed(KEY_NSPIRE_LEFT) || isKeyPressed(KEY_NSPIRE_4))
            image.x -= speed;
        if (isKeyPressed(KEY_NSPIRE_RIGHT) || isKeyPressed(KEY_NSPIRE_6))
            image.x += speed;

        // Up left/right
        if (isKeyPressed(KEY_NSPIRE_LEFTUP) || isKeyPressed(KEY_NSPIRE_7))
        {
            image.y -= speed;
            image.x -= speed;
        }
        if (isKeyPressed(KEY_NSPIRE_UPRIGHT) || isKeyPressed(KEY_NSPIRE_9))
        {
            image.y -= speed;
            image.x += speed;
        }

        // Down left/right
        if (isKeyPressed(KEY_NSPIRE_DOWNLEFT) || isKeyPressed(KEY_NSPIRE_1))
        {
            image.y += speed;
            image.x -= speed;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHTDOWN) || isKeyPressed(KEY_NSPIRE_3))
        {
            image.y += speed;
            image.x += speed;
        }

        if (isKeyPressed(KEY_NSPIRE_PLUS))
            speed += 1;
        if (isKeyPressed(KEY_NSPIRE_MINUS))
            speed -= 1;

        if (isKeyPressed(KEY_NSPIRE_DEL) || isKeyPressed(KEY_NSPIRE_5))
        {
            image.x = 0;
            image.y = 0;
            speed = 1;
        }

        // Draw the image
        clearBuffer(RGB(200, 200, 200), buffer);
        drawImage(&image, buffer);
        if (speed < 0)
            drawChar(0, 0, '-', 1, RED, buffer);
        else
            drawChar(0, 0, '+', 1, RED, buffer);
        drawChar(8, 0, '0' + abs(speed) / 10, 1, RED, buffer);
        drawChar(16, 0, '0' + abs(speed) % 10, 1, RED, buffer);

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
