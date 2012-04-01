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
    char pathTileset[] = "/documents/Examples/rpg/imgTileset.tns";
    //char pathTileset[] = "/documents/ndless/dev/rpg/imgTileset.tns";

    // Tileset
    Tileset tileset;
    tileset.tiles = NULL;
    tileset.nbTiles = 0;
    initImage(&tileset.img);

    // Map
    int i, j, ti, tj, offset_x = 0, offset_y = 0;
    Map myMap;
    myMap.map = NULL;
    myMap.tileset = &tileset;
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
        {
            offset_y -= SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_2))
        {
            offset_y += SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_4))
        {
            offset_x -= SPEED;
        }
        if (isKeyPressed(KEY_NSPIRE_6))
        {
            offset_x += SPEED;
        }

        /* Begin to draw on the buffer */
        clearBuffer(BLACK, buffer);

        // Draw the map
        /*for (i = offset_x / CELL_SIZE - 1; i < (offset_x + SCREEN_WIDTH) / CELL_SIZE + 1; i++)
        {
            tile.x = i * CELL_SIZE + offset_x % CELL_SIZE;
            for (j = offset_y / CELL_SIZE - 1; j < (offset_y + SCREEN_HEIGHT) / CELL_SIZE + 1; j++)
            {
                tile.y = j * CELL_SIZE + offset_y % CELL_SIZE;

                ti = (i < 0) ? 0 : ((i >= myMap.w) ? myMap.w : i);
                tj = (j < 0) ? 0 : ((j >= myMap.h) ? myMap.h : j);

                tile.offset_x = myMap.tileset->tiles[myMap.map[ti + tj * myMap.w]].x;
                tile.offset_y = myMap.tileset->tiles[myMap.map[ti + tj * myMap.w]].y;

                drawImagesubrect(&tile, buffer);
            }
        }*/
        for (i = 0; i < SCREEN_WIDTH / CELL_SIZE + 1; i++)
        {
            tile.x = i * CELL_SIZE - offset_x % CELL_SIZE;
            for (j = 0; j < SCREEN_HEIGHT / CELL_SIZE + 2; j++)
            {
                tile.y = j * CELL_SIZE - offset_y % CELL_SIZE;

                ////////////////////////////////////////////////////////////////////////
                if (i + (offset_x / CELL_SIZE) < 0)
                    ti = 0;
                else if (i + (offset_x / CELL_SIZE) >= myMap.w)
                    ti = myMap.w;
                else
                    ti = i + (offset_x / CELL_SIZE);
                ////////////////////////////////////////////////////////////////////////
                if (j + (offset_y / CELL_SIZE) < 0)
                    tj = 0;
                else if (j + (offset_y / CELL_SIZE) >= myMap.h)
                    tj = myMap.h;
                else
                    tj = j + (offset_y / CELL_SIZE);
                ////////////////////////////////////////////////////////////////////////

                /*ti = (i + (offset_x / CELL_SIZE) < 0) ? (0) : ((i + (offset_x / CELL_SIZE) >= myMap.w) ? (myMap.w) : (i + (offset_x / CELL_SIZE)));
                tj = (j + (offset_y / CELL_SIZE) < 0) ? (0) : ((j + (offset_y / CELL_SIZE) >= myMap.h) ? (myMap.h) : (j + (offset_y / CELL_SIZE)));*/

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
