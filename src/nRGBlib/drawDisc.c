#include <nGEO.h>

/// Dessine un disque en couleur
void drawDiscRGB(short x_centre, short y_centre, short rayon, char R, char G, char B)
{ // TODO: Vérifier si le dessin n'est pas trop grand
    short x = 0;
    short y = rayon;
    short d = 3 - (2 * rayon);

    while (y >= x)
    {
        drawBox2DRGB(x_centre - x, y_centre - y - 1, 2 * x + 1, 1, R, G, B); // 1
        drawBox2DRGB(x_centre - x, y_centre + y - 1, 2 * x + 1, 1, R, G, B); // 2
        drawBox2DRGB(x_centre - y, y_centre - x - 1, 2 * y + 1, 1, R, G, B); // 3
        drawBox2DRGB(x_centre - y, y_centre + x - 1, 2 * y + 1, 1, R, G, B); // 4

        if (d < 0)
            d += (4 * x) + 6;
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
void drawDiscColor(short x, short y, short rayon, Color col)
{
    drawDiscRGB(x, y, rayon, col.R, col.G, col.B);
}
