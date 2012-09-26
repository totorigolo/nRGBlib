#include <os.h>
#include <nIMAGE.h>
#include <nMATHS.h>
#include <nGEO.h>
#include "map.h"

int main(int argc, char* argv[])
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Images' path
    char pathPerso[] = "/documents/Examples/rpg/imgPerso.tns";

    // Tileset
    Tileset tileset;
    tileset.tiles = NULL;
    tileset.nbTiles = 0;
    initImage(&tileset.img);

    // Map
    int i, j, ti, tj, d;
    Map myMap;
    myMap.map = NULL;
    myMap.tileset = &tileset;
    myMap.offset_x = 0; myMap.offset_y = 0;
    loadFromFile(&myMap, "/documents/Examples/rpg/bin.map.tns");

    // Load the perso's image
    int speed = 2;
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
            imgPerso.y -= speed;
        if (isKeyPressed(KEY_NSPIRE_DOWN))
            imgPerso.y += speed;

        // Left and right
        if (isKeyPressed(KEY_NSPIRE_LEFT))
            imgPerso.x -= speed;
        if (isKeyPressed(KEY_NSPIRE_RIGHT))
            imgPerso.x += speed;

        // Up left/right
        if (isKeyPressed(KEY_NSPIRE_LEFTUP))
        {
            imgPerso.y -= speed;
            imgPerso.x -= speed;
        }
        if (isKeyPressed(KEY_NSPIRE_UPRIGHT))
        {
            imgPerso.y -= speed;
            imgPerso.x += speed;
        }

        // Down left/right
        if (isKeyPressed(KEY_NSPIRE_DOWNLEFT))
        {
            imgPerso.y += speed;
            imgPerso.x -= speed;
        }
        if (isKeyPressed(KEY_NSPIRE_RIGHTDOWN))
        {
            imgPerso.y += speed;
            imgPerso.x += speed;
        }

        if (isKeyPressed(KEY_NSPIRE_PLUS))
            speed += 1;
        if (isKeyPressed(KEY_NSPIRE_MINUS))
            speed -= 1;

        if (isKeyPressed(KEY_NSPIRE_8) && (myMap.offset_y - speed) >= 0)
            myMap.offset_y -= speed;
        if (isKeyPressed(KEY_NSPIRE_2) && (myMap.offset_y + speed) < ((myMap.h * CELL_SIZE) - SCREEN_HEIGHT))
            myMap.offset_y += speed;
        if (isKeyPressed(KEY_NSPIRE_4) && (myMap.offset_x - speed) >= 0)
            myMap.offset_x -= speed;
        if (isKeyPressed(KEY_NSPIRE_6) && (myMap.offset_x + speed) < ((myMap.w * CELL_SIZE) - SCREEN_WIDTH))
            myMap.offset_x += speed;

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

                if (tj >= myMap.h)
                    tj = myMap.h-1;

                tile.offset_x = myMap.tileset->tiles[myMap.map[ti + tj * myMap.w]].x;
                tile.offset_y = myMap.tileset->tiles[myMap.map[ti + tj * myMap.w]].y;

                drawImageSubrect(&tile, buffer);
            }
        }

        // Draw the perso
        drawImage(&imgPerso, buffer);

        // Draw the speed
        if (speed < 0)
            drawChar(0, 0, '-', 1, RED, buffer);
        else
            drawChar(0, 0, '+', 1, RED, buffer);

        drawChar(8, 0, '0' + abs(speed) / 10, 1, RED, buffer);
        drawChar(16, 0, '0' + abs(speed) % 10, 1, RED, buffer);

        // Display our buffer on the screen
        display(buffer);

        if (!has_colors || !lcd_isincolor())
        {
            /** Doesn't work with CX !! **/
            // Wait to save the battery
            idle();
            while (!any_key_pressed());
            idle();
        }
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
