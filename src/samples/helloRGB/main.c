#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

int main(void)
{
    // Sers à rien mais obligatoire pour le moment
    lcd_isincolor();
    lcd_ingray();
    lcd_incolor();
    _scrsize();

    //drawStr(short x, short y, char* str, char size, char endl, Color col);
    drawStr(0, 0, "Hello !", 2, 0, RGB(137, 255, 137)); // Verdâtre
    drawSquare_(0, 30, 20, RGB(255, 0, 255)); // Rose
    Color c = getPixel(0, 35);//
    printf("R = %d, G = %d, B = %d\n", c.R, c.G, c.B);
//
    // On attends
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(50);
    }

    // Rends la main à l'OS
    return 0;
}
