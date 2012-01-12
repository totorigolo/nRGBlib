#include <os.h>
#include <nGEO.h>
#include <nTILE.h>
#include <nMATHS.h>
#include "tileset.h"

int main(void)
{
    // Sers à rien mais obligatoire pour le moment
    lcd_isincolor();
    lcd_ingray();
    lcd_incolor();
    _scrsize();

    int x, y, radius, R, G, B;

    // On efface l'écran
    clearScreen(RGB(0, 0, 0));

    // Dessine tout !
    drawTriangle_(0, 0, 319, 0, 319, 239, RGB(37, 136, 218));
    drawTriangle_(0, 0, 0, 239, 319, 239, RGB(218, 37, 136));
    drawBox_(300, 0, 20, 10, RGB(0, 95, 107));
    drawDisc_(120, 120, 30, RGB(0, 0, 255));
    drawDisc_(160, 120, 30, RGB(128, 128, 255));
    drawDisc_(120, 160, 30, RGB(128, 0, 255));
    drawDisc_(160, 160, 30, RGB(255, 123, 48));
    drawTriangle_(140, 20, 110, 80, 160, 40, RGB(37, 136, 218));
    drawTriangle_(145, 15, 145, 60, 120, 40, RGB(218, 37, 136));
    drawTriangle_(135, 10, 175, 50, 130, 30, RGB(136, 218, 37));
    drawBox_(120, 120, 40, 40, RGB(0, 151, 75));
    drawDisc_(250, 60, 35, RGB(128, 128, 255));
    drawCircle_(240, 50, 40, RGB(175, 48, 107));
    drawLine_(290, 180, 310, 150, RGB(0, 255, 0));
    drawLine_(280, 170, 300, 140, RGB(255, 255, 0));
    drawLine_(270, 160, 290, 130, RGB(255, 0, 0));
    drawChar( 50,   5, 'n', 1, RGB(255, 217, 76));
    drawChar(260,  60, 'Y', 1, RGB(255, 217, 76));
    drawChar( 60, 200, 'O', 1, RGB(255, 217, 76));
    drawChar( 37, 136, 'q', 1, RGB(255, 0, 0));
    drawChar(302,  39, 'M', 1, RGB(0, 217, 28));
    drawChar(258,  17, 'X', 1, RGB(255, 128, 0));
    drawTile8Unicolor(20, 80, 1, tile_bonhommeU);
    drawTile8Multicolors(40, 80, 1, tile_bonhommeM);
    drawTile8Multicolors(30, 20, 5, tile_bonhommeM);
    drawStr(0, 240 - CHAR_HEIGHT * 3, "Ctrl to Bubble Land!", 2, 0, RGB(0, 255, 255));
    drawStrBckg(0, 240 - CHAR_HEIGHT, "Esc to Quit", 1, 0, RGB(255, 0, 0), RGB(255, 255, 255));
    drawStrBckg(SCREEN_WIDTH - 13 * CHAR_WIDTH, 240 - CHAR_HEIGHT, "by totorigolo", 1, 0, RGB(255, 0, 0), RGB(0, 255, 255));

    drawCircle_(289, 30, 30, RGB(255, 255, 255));
    drawDisc_(15, 15, 15, RGB(255, 255, 255));

    // On attends
    while (!isKeyPressed(KEY_NSPIRE_ESC))
    {
        rand();
        //sleep(50);
        if (isKeyPressed(KEY_NSPIRE_CTRL))
        {
            while (!isKeyPressed(KEY_NSPIRE_ESC))
            {
                x = randMinMax(0, 319);
                y = randMinMax(0, 239);
                radius = randMinMax(5, 50);
                R = randMinMax(0, 255);
                G = randMinMax(0, 255);
                B = randMinMax(0, 255);

                if (randMinMax(0, 1))
                {
                    //drawDisc_(randMinMax(0, 320), randMinMax(0, 240), randMinMax(5, 50), RGB(randMinMax(0, 255), randMinMax(0, 255), randMinMax(0, 255)));
                    printf("Disque - %d, %d, %d | %d, %d, %d\n", x, y, radius, R, G, B);
                    drawDisc_(x, y, radius, RGB(R, G, B));
                    printf("Done\n\n");
                }
                else
                {
                    //drawCircle_(randMinMax(0, 320), randMinMax(0, 240), randMinMax(5, 50), RGB(randMinMax(0, 255), randMinMax(0, 255), randMinMax(0, 255)));
                    printf("Cercle - %d, %d, %d | %d, %d, %d\n", x, y, radius, R, G, B);
                    drawCircle_(x, y, radius, RGB(R, G, B));
                    printf("Done\n\n");
                }
            }
            drawStr(0, 240 - CHAR_HEIGHT * 3, "Ctrl to Bubble Land!", 2, 0, RGB(0, 255, 255));
            drawStrBckg(0, 240 - CHAR_HEIGHT, "Esc to Quit", 1, 0, RGB(255, 0, 0), RGB(255, 255, 255));
        }
    }

    // Rends la main à l'OS
    return 0;
}

































