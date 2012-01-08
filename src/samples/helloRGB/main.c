#include <os.h>
//#include <nGUI.h>

int main(void)
{
printf("int = %d | short = %d | char = %d\n", sizeof(int), sizeof(short), sizeof(char));
    // Sers à rien mais obligatoire pour le moment
    lcd_isincolor();
    lcd_ingray();
    lcd_incolor();
    _scrsize();

/*    drawStrRGB(0, 0, "Hello !", 2, 0, 137, 255, 137);
    drawBox2DRGB(0, 30, 20, 20, 21, 249, 64);
    getPixel(0, 35);
///*/
    // On attends
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(50);
    }

    // Rends la main à l'OS
    return 0;
}
