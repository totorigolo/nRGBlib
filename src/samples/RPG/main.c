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
#include <nMATHS.h>
#include <nGEO.h>

#define SPEED 2
#define CELL_SIZE 32

int main(int argc, char* argv[])
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Map
    int i, j;
    char map[(SCREEN_WIDTH / 2) + 1][(SCREEN_HEIGHT / 2) + 1];

    // Create the image
    Image imgPerso, imgTileset; imgPerso.data = NULL; imgTileset.data = NULL;
    ImageSubrect tile; tile.image = NULL;

    // "Srand"
    clearScreen(BLACK, buffer);
    drawStr(0, 0, "Clic to gen!", 1, 1, CYAN, GetDirectScreenBuffer());
    while (!any_key_pressed())
        rand();
    while (any_key_pressed())
        rand();

    // Map generation
    for (i = 0; i < (SCREEN_WIDTH / CELL_SIZE) + 1; i++)
        for (j = 0; j < (SCREEN_HEIGHT / CELL_SIZE) + 1; j++)
            map[i][j] = randMinMax(0, 2);

    //char pathPerso[] = "/documents/Examples/rpg/imgPerso.tns";
    char pathPerso[] = "/documents/ndless/dev/rpg/imgPerso.tns";

    //char pathTileset[] = "/documents/Examples/rpg/imgTileset.tns";
    char pathTileset[] = "/documents/ndless/dev/rpg/imgTileset.tns";

    // Load the image
    loadImage(&imgPerso, pathPerso);
    loadImage(&imgTileset, pathTileset);
    setImage(&tile, &imgTileset);
    tile.w = CELL_SIZE;
    tile.h = CELL_SIZE;

    clearScreen(BLACK, buffer);
    while (1)
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_ESC))
            break;

        // Up and down
        if (isKeyPressed(KEY_NSPIRE_UP) || isKeyPressed(KEY_NSPIRE_8))
            imgPerso.y -= SPEED;
        if (isKeyPressed(KEY_NSPIRE_DOWN) || isKeyPressed(KEY_NSPIRE_2))
            imgPerso.y += SPEED;

        // Left and right
        if (isKeyPressed(KEY_NSPIRE_LEFT) || isKeyPressed(KEY_NSPIRE_4))
            imgPerso.x -= SPEED;
        if (isKeyPressed(KEY_NSPIRE_RIGHT) || isKeyPressed(KEY_NSPIRE_6))
            imgPerso.x += SPEED;

        // Up left/right
        if (isKeyPressed(KEY_NSPIRE_LEFTUP) || isKeyPressed(KEY_NSPIRE_7))
        {
            imgPerso.y -= SPEED;
            imgPerso.x -= SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_UPRIGHT) || isKeyPressed(KEY_NSPIRE_9))
        {
            imgPerso.y -= SPEED;
            imgPerso.x += SPEED;
        }

        // Down left/right
        if (isKeyPressed(KEY_NSPIRE_DOWNLEFT) || isKeyPressed(KEY_NSPIRE_1))
        {
            imgPerso.y += SPEED;
            imgPerso.x -= SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHTDOWN) || isKeyPressed(KEY_NSPIRE_3))
        {
            imgPerso.y += SPEED;
            imgPerso.x += SPEED;
        }

        /* Begin to draw on the buffer */
        clearBuffer(BLACK, buffer);

        // Draw the map
        for (i = 0; i < (SCREEN_WIDTH / CELL_SIZE) + 1; i++)
        {
            tile.x = i * CELL_SIZE;
            for (j = 0; j < (SCREEN_HEIGHT / CELL_SIZE) + 1; j++)
            {
                tile.y = j * CELL_SIZE;

                if (map[i][j] == 0)
                {
                    tile.offset_x = 0;
                    tile.offset_y = 0;
                }
                if (map[i][j] == 1)
                {
                    tile.offset_x = CELL_SIZE;
                    tile.offset_y = 0;
                }
                if (map[i][j] == 2)
                {
                    tile.offset_x = 0;
                    tile.offset_y = CELL_SIZE;
                }

                drawImagesubrect(&tile, buffer);
            }
        }

        // Draw the perso
        drawImage(&imgPerso, buffer);

        // Display our buffer on the screen
        display(buffer);

        // Wait to save the battery
        idle();
        while (!any_key_pressed());
        idle();
    }

    // Delete our image
    deleteImage(&imgPerso);
    deleteImage(&imgTileset);

    // Free our screen buffer
    free(buffer);

    // And quit
    return 0;
}
