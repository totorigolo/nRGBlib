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
#include "map.h"

#define SPEED 2

int main(int argc, char* argv[])
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Images' path
    char pathPerso[] = "/documents/Examples/rpg/imgPerso.tns";
    //char pathPerso[] = "/documents/ndless/dev/rpg/imgPerso.tns";

    // Tileset
    Tileset tileset;
    tileset.tiles = NULL;
    tileset.nbTiles = 0;
    initImage(&tileset.img);

    // Map
    int i, j, ti, tj;
    Map myMap;
    myMap.map = NULL;
    myMap.tileset = &tileset;
    myMap.offset_x = 0; myMap.offset_y = 0;
    loadFromFile(&myMap, "/documents/Examples/rpg/bin.map.tns");

    // Load the perso's image
    Image imgPerso;
    ImageSubrect tile; tile.image = NULL;
    initImage(&imgPerso);
    loadImage(&imgPerso, pathPerso);

    // Set the tile
    setImage(&tile, &tileset.img);
    tile.w = CELL_SIZE;
    tile.h = CELL_SIZE;

    clearScreen(BLACK, buffer);
    while (1)
    {
        // Events processing
        if (isKeyPressed(KEY_NSPIRE_ESC))
            break;

        // Up and down
        if (isKeyPressed(KEY_NSPIRE_UP))
            imgPerso.y -= SPEED;
        if (isKeyPressed(KEY_NSPIRE_DOWN))
            imgPerso.y += SPEED;

        // Left and right
        if (isKeyPressed(KEY_NSPIRE_LEFT))
            imgPerso.x -= SPEED;
        if (isKeyPressed(KEY_NSPIRE_RIGHT))
            imgPerso.x += SPEED;

        // Up left/right
        if (isKeyPressed(KEY_NSPIRE_LEFTUP))
        {
            imgPerso.y -= SPEED;
            imgPerso.x -= SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_UPRIGHT))
        {
            imgPerso.y -= SPEED;
            imgPerso.x += SPEED;
        }

        // Down left/right
        if (isKeyPressed(KEY_NSPIRE_DOWNLEFT))
        {
            imgPerso.y += SPEED;
            imgPerso.x -= SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHTDOWN))
        {
            imgPerso.y += SPEED;
            imgPerso.x += SPEED;
        }

        if (isKeyPressed(KEY_NSPIRE_8))
            myMap.offset_y -= SPEED;
        if (isKeyPressed(KEY_NSPIRE_2))
            myMap.offset_y += SPEED;
        if (isKeyPressed(KEY_NSPIRE_4))
            myMap.offset_x -= SPEED;
        if (isKeyPressed(KEY_NSPIRE_6))
            myMap.offset_x += SPEED;

        /* Begin to draw on the buffer */
        clearBuffer(BLACK, buffer);

        // Draw the map
        for (i = 0; i < SCREEN_WIDTH / CELL_SIZE + 1; i++)
        {
            tile.x = i * CELL_SIZE - myMap.offset_x % CELL_SIZE;
            for (j = 0; j < SCREEN_HEIGHT / CELL_SIZE + 2; j++)
            {
                tile.y = j * CELL_SIZE - myMap.offset_y % CELL_SIZE;

                ti = (i + (myMap.offset_x / CELL_SIZE) < 0) ? (0) : ((i + (myMap.offset_x / CELL_SIZE) >= myMap.w) ? (myMap.w) : (i + (myMap.offset_x / CELL_SIZE)));
                tj = (j + (myMap.offset_y / CELL_SIZE) < 0) ? (0) : ((j + (myMap.offset_y / CELL_SIZE) >= myMap.h) ? (myMap.h) : (j + (myMap.offset_y / CELL_SIZE)));

                tile.offset_x = myMap.tileset->tiles[myMap.map[ti + tj * myMap.w]].x;
                tile.offset_y = myMap.tileset->tiles[myMap.map[ti + tj * myMap.w]].y;

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
    deleteImage(&tileset.img);

    // Delete our map
    free(myMap.map);
    free(tileset.tiles);

    // Free our screen buffer
    free(buffer);

    // And quit
    return 0;
}
