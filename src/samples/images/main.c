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
    //ScreenBuffer buffer = GetNewScreenBuffer();

    // Create the image
    Image image;

    // Find the image path
    int len = strrchr(argv[0], '/') - argv[0] + 1;
    char path[len + strlen("img2.h.tns")];
    memcpy(path, argv[0], len);
    memcpy(path + len * sizeof(char), "img2.h.tns", strlen("img2.h.tns"));

    // Load the image
    loadImage(&image, path);
    image.x = SCREEN_WIDTH / 2 - image.w / 2;
    image.y = SCREEN_HEIGHT / 2 - image.h / 2;

    // Draw the image
    clearScreen(WHITE, NULL);
    drawImage(&image, GetDirectScreenBuffer());

    /*drawLine_(290, 180, 310, 150, RGB(0, 255, 0), buffer);
    drawLine_(280, 170, 300, 140, RGB(255, 255, 0), buffer);
    drawLine_(270, 160, 290, 130, RGB(255, 0, 0), buffer);
    drawChar( 50,   5, 'n', 1, RGB(255, 217, 76), buffer);
    drawChar(260,  60, 'Y', 1, RGB(255, 217, 76), buffer);
    drawChar( 60, 200, 'O', 1, RGB(255, 217, 76), buffer);
    drawChar( 37, 136, 'q', 1, RGB(255, 0, 0), buffer);
    drawChar(302,  39, 'M', 1, RGB(0, 217, 28), buffer);
    drawChar(258,  17, 'X', 1, RGB(255, 128, 0), buffer);*/

    // Display our buffer on the screen
    //display(buffer);

    // Wait
    while (any_key_pressed());
    while (!any_key_pressed())
        sleep(100);

    // Free our screen buffer
printf("111111\n");
    //free(buffer);
printf("22222\n");
    //free(image.data);
printf("333333\n");

    // And quit
    return 0;
}
