#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

int main()
{
    // Sers à rien mais obligatoire pour le moment
    lcd_isincolor();
    lcd_ingray();
    lcd_incolor();
    _scrsize();

    // Couleur du second "Hello !"
    Color c1 = RGB(123, 125, 174); // Violet-gris

    drawSquare_(0, 30, 20, RGB(255, 0, 255)); // Rose
    drawStr(0, 0, "Hello !", 2, 0, RGB(137, 255, 137)); // Verdâtre
    drawStr(100, 100, "Hello !", 2, 0, c1);

    // Debug de getPixel...
    Color c = getPixel(0, 35);
    printf("\nR = %d\nG = %d\nB = %d\nRGB = %d\n\n", c.R, c.G, c.B, c.raw);

    // On attends
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(50);
    }

    // Rends la main à l'OS
    return 0;
}
