#include <os.h>
#include <nGEO.h>
#include <nGUI.h>

int main()
{
    // Couleur du second "Hello !"
    Color c1 = RGB(123, 125, 174); // Violet-gris
    Line l1 = { 20, 20, 120, 120 };
    Line l2 = { .x1 = 40, .x2 = 60, .y1 = 100, .y2 = 140 };

    drawSquare_(0, 30, 20, RGB(255, 0, 255)); // Rose
    drawStr(0, 0, "Hello !", 2, 0, RGB(137, 255, 137)); // Verdâtre
    drawStr(100, 100, "Hello !", 2, 0, c1);
    drawLine(&l1, c1);
    drawLine(&l2, RGB(255, 0, 128));

    // Debug de getPixel...
    Color c = getPixel(0, 35);
    printf("\nR = %d\nG = %d\nB = %d\nRGB = %d\n\n", c.R, c.G, c.B, c.raw);

    // On attends
    while (any_key_pressed());
    while (!any_key_pressed())
    {
        sleep(100);
    }

    // Rends la main à l'OS
    return 0;
}
