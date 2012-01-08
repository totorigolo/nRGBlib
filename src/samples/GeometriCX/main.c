#include <os.h>
#include <nGEO.h>
#include <nTILE.h>
#include "tileset.h"

int main(void)
{
    // Formes géométriques
    Triangle tri = new_Triangle(21, 12, 211, 122, 212, 121);

    // Sers à rien mais obligatoire pour le moment
    lcd_isincolor();
    lcd_ingray();
    lcd_incolor();
    _scrsize();

    // On efface l'écran
    clearScreenRGB(0, 0, 0);

    // Dessine tout !
    drawTriangleRGB(0, 0, 319, 0, 319, 239, 37, 136, 218);
    drawTriangleRGB(0, 0, 0, 239, 319, 239, 218, 37, 136);
    drawBox2DRGB(300, 0, 20, 10, 0, 95, 107);
    drawDiscRGB(120, 120, 30, 0, 0, 255);
    drawDiscRGB(160, 120, 30, 128, 128, 255);
    drawDiscRGB(120, 160, 30, 128, 0, 255);
    drawDiscRGB(160, 160, 30, 255, 123, 48);
    drawTriangleRGB(tri, 136, 218, 37);
    drawTriangleRGB(140, 20, 160, 40, 110, 80, 37, 136, 218);
    drawTriangleRGB(145, 15, 145, 60, 120, 40, 218, 37, 136);
    drawTriangleRGB(135, 10, 175, 50, 130, 30, 136, 218, 37);
    drawBox2DRGB(120, 120, 40, 40, 0, 151, 75);
    drawDiscRGB(250, 60, 35, 128, 128, 255);
    drawCircleRGB(240, 50, 40, 175, 48, 107);
    drawLineRGB(290, 180, 310, 150, 0, 255, 0);
    drawLineRGB(280, 170, 300, 140, 255, 255, 0);
    drawLineRGB(270, 160, 290, 130, 255, 0, 0);
    drawCharRGB(50, 5, 'n', 1, 255, 217, 76);
    drawCharRGB(260, 60, 'Y', 1, 255, 217, 76);
    drawCharRGB(60, 200, 'O', 1, 255, 217, 76);
    drawCharRGB(37, 136, 'q', 1, 255, 0, 0);
    drawCharRGB(302, 39, 'M', 1, 0, 217, 28);
    drawCharRGB(258, 17, 'X', 1, 255, 128, 0);
    drawTile8Unicolor(20, 80, 1, tile_bonhommeU);
    drawTile8Multicolors(40, 80, 1, tile_bonhommeM);
    drawTile8Multicolors(30, 20, 5, tile_bonhommeM);
    drawStrRGB(0, 240 - CHAR_HEIGHT * 3, "Ctrl to Bubble Land!", 2, 0, 0, 255, 255);
    drawStrRGBFond(0, 240 - CHAR_HEIGHT, "Esc to Quit", 1, 0, 255, 0, 0, 255, 255, 255);
    drawStrRGBFond(SCREEN_WIDTH - 13 * CHAR_WIDTH, 240 - CHAR_HEIGHT, "by totorigolo", 1, 0, 255, 0, 0, 0, 255, 255);

    drawCircleRGB(289, 30, 30, 255, 255, 255);
    drawDiscRGB(15, 15, 15, 255, 255, 255);

    // On attends
    while (!isKeyPressed(KEY_NSPIRE_ESC))
    {
        if (isKeyPressed(KEY_NSPIRE_CTRL))
        {
            while (!isKeyPressed(KEY_NSPIRE_ESC))
            {
                if (randMinMax(0, 1))
                    drawDiscRGB(randMinMax(0, 320), randMinMax(0, 240), randMinMax(5, 50), randMinMax(0, 255), randMinMax(0, 255), randMinMax(0, 255));
                else
                    drawCircleRGB(randMinMax(0, 320), randMinMax(0, 240), randMinMax(5, 50), randMinMax(0, 255), randMinMax(0, 255), randMinMax(0, 255));
            }
            drawStrRGB(0, 240 - CHAR_HEIGHT * 3, "Ctrl to Bubble Land!", 2, 0, 0, 255, 255);
            drawStrRGBFond(0, 240 - CHAR_HEIGHT, "Esc to Quit", 1, 0, 255, 0, 0, 255, 255, 255);
        }
    }

    // Rends la main à l'OS
    return 0;
}

































