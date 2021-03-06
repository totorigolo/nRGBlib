#include <os.h>
#include <nGEO.h>
#include <nTILE.h>
#include <nMATHS.h>
#include "tileset.h"

int main(void)
{
    // Create a new screen buffer
    ScreenBuffer buffer = GetNewScreenBuffer();

    // Clear screen in black and clear our screen buffer too
    clearScreen(BLACK, buffer);

    // Draw all !
    drawTriangle_(0, 0, 319, 0, 319, 239, RGB(37, 136, 218), buffer);
    drawTriangle_(0, 0, 0, 239, 319, 239, RGB(218, 37, 136), buffer);
    drawBox_(300, 0, 20, 10, RGB(0, 95, 107), buffer);
    drawDisc_(120, 120, 30, RGB(0, 0, 255), buffer);
    drawDisc_(160, 120, 30, RGB(128, 128, 255), buffer);
    drawDisc_(120, 160, 30, RGB(128, 0, 255), buffer);
    drawDisc_(160, 160, 30, RGB(255, 123, 48), buffer);
    drawTriangle_(140, 20, 110, 80, 160, 40, RGB(37, 136, 218), buffer);
    drawTriangle_(145, 15, 145, 60, 120, 40, RGB(218, 37, 136), buffer);
    drawTriangle_(135, 10, 175, 50, 130, 30, RGB(136, 218, 37), buffer);
    drawBox_(120, 120, 40, 40, RGB(0, 151, 75), buffer);
    drawDisc_(250, 60, 35, RGB(128, 128, 255), buffer);
    drawCircle_(240, 50, 40, RGB(175, 48, 107), buffer);
    drawLine_(290, 180, 310, 150, RGB(0, 255, 0), buffer);
    drawLine_(280, 170, 300, 140, RGB(255, 255, 0), buffer);
    drawLine_(270, 160, 290, 130, RGB(255, 0, 0), buffer);
    drawChar( 50,   5, 'n', 1, RGB(255, 217, 76), buffer);
    drawChar(260,  60, 'Y', 1, RGB(255, 217, 76), buffer);
    drawChar( 60, 200, 'O', 1, RGB(255, 217, 76), buffer);
    drawChar( 37, 136, 'q', 1, RGB(255, 0, 0), buffer);
    drawChar(302,  39, 'M', 1, RGB(0, 217, 28), buffer);
    drawChar(258,  17, 'X', 1, RGB(255, 128, 0), buffer);
    drawTile8Unicolor(20, 80, 1, tile_bonhommeU, buffer);
    drawTile8Multicolors(40, 80, 1, tile_bonhommeM, buffer);
    drawTile8Multicolors(30, 20, 5, tile_bonhommeM, buffer);
    drawStr(0, 240 - CHAR_HEIGHT * 3, "Ctrl to Bubble Land!", 2, 0, CYAN, buffer);
    drawStrBckg(0, 240 - CHAR_HEIGHT, "Esc to Quit", 1, 0, RED, WHITE, buffer);
    drawStrBckg(SCREEN_WIDTH - 21 * CHAR_WIDTH, 240 - CHAR_HEIGHT, "nRGBlib by totorigolo", 1, 0, RED, CYAN, buffer);
    drawCircle_(289, 30, 30,WHITE, buffer);
    drawDisc_(15, 15, 15, WHITE, buffer);

    // Display our buffer on the screen
    display(buffer);

    // Wait
    while (!isKeyPressed(KEY_NSPIRE_ESC))
    {
        rand();
        sleep(50);
        if (isKeyPressed(KEY_NSPIRE_CTRL)) // Bubble Land !
        {
            while (!isKeyPressed(KEY_NSPIRE_ESC))
            {
                // Draw either a disc or a circle
                if (randMinMax(0, 1))
                    drawDisc_(randMinMax(0, 320), randMinMax(0, 240), randMinMax(5, 50), RGB(randMinMax(0, 255), randMinMax(0, 255), randMinMax(0, 255)), buffer);
                else
                    drawCircle_(randMinMax(0, 320), randMinMax(0, 240), randMinMax(5, 50), RGB(randMinMax(0, 255), randMinMax(0, 255), randMinMax(0, 255)), buffer);

                // Display our buffer on the screen
                display(buffer);
            }
            // Draw texts
            drawStr(0, 240 - CHAR_HEIGHT * 3, "Ctrl to Bubble Land!", 2, 0, CYAN, buffer);
            drawStrBckg(0, 240 - CHAR_HEIGHT, "Esc to Quit", 1, 0, RED, WHITE, buffer);

            // Display our buffer on the screen
            display(buffer);

            // Wait to not quit immediately
            while (isKeyPressed(KEY_NSPIRE_ESC));
        }
    }

    // Free our screen buffer
    free(buffer);

    // Quit
    return 0;
}
