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
    image.data = NULL;

    // Find the image path
    int len = strrchr(argv[0], '/') - argv[0] + 1;
    char path[len + strlen("img.h.tns") + 1];
    memcpy(path, argv[0], len);
    memcpy(path + len * sizeof(char), "img.h.tns", strlen("img.h.tns"));

    // Load the image
    loadImage(&image, path);
    image.x = SCREEN_WIDTH / 2 - image.w / 2;
    image.y = SCREEN_HEIGHT / 2 - image.h / 2;

    clearScreen(RGB(200, 200, 200), buffer);
    while (1)
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_ESC))
            break;

        if (isKeyPressed(KEY_NSPIRE_UP) || isKeyPressed(KEY_NSPIRE_8))
            image.y -= 6;
        if (isKeyPressed(KEY_NSPIRE_DOWN) || isKeyPressed(KEY_NSPIRE_2))
            image.y += 6;
        if (isKeyPressed(KEY_NSPIRE_LEFT) || isKeyPressed(KEY_NSPIRE_4))
            image.x -= 6;
        if (isKeyPressed(KEY_NSPIRE_RIGHT) || isKeyPressed(KEY_NSPIRE_6))
            image.x += 6;

        // Draw the image
        clearBuffer(RGB(200, 200, 200), buffer);
        drawImage(&image, buffer);

        // Display our buffer on the screen
        display(buffer);
    }

    printf("Deleting all things...\n");
    // Free our screen buffer
    printf("Buffer...\n");
    free(buffer);
    printf("Img.data...\n");
    if (image.data != NULL)
        free(image.data);
    printf("Done!\n");

    // And quit
    sleep(300);
    return 0;
}
