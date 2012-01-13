#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

int main()
{
    // Ecran couleur (si possible)
    lcd_incolor();

    // Un ligne simple pour la couleur
    Color c1 = RGB(233, 0, 128); // Violet-gris

    // Deux méthodes différentes pour créer une forme
    Line l1 = { SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5, SCREEN_WIDTH / 2 + CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 + CHAR_HEIGHT + 5 };
    Line l2 = { .x1 = 76, .x2 = 244, .y1 = 140, .y2 = 140 };

    // On affiche tout ce beau monde
    drawStr(SCREEN_WIDTH / 2 - CHAR_WIDTH * 7, SCREEN_HEIGHT / 2 - CHAR_HEIGHT / 2, "Hello !", 2, 0, RGB(50, 205, 50)); // Verdâtre
    drawLine(&l1, c1);
    drawLine(&l2, c1);

    // On attends
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(100);
    }

    // Rends la main à l'OS
    return 0;
}
