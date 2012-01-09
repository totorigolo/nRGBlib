#include <nGEO.h>

/// Dessine un disque en couleur
void drawDiscRGB_(short x_centre, short y_centre, short rayon, char R, char G, char B)
{ // TODO: Vérifier si le dessin n'est pas trop grand
    short x = 0;
    short y = rayon;
    short d = 3 - (2 * rayon);

    while (y >= x)
    {
        drawBoxRGB_(x_centre - x, y_centre - y - 1, 2 * x + 1, 1, R, G, B); // 1
        drawBoxRGB_(x_centre - x, y_centre + y - 1, 2 * x + 1, 1, R, G, B); // 2
        drawBoxRGB_(x_centre - y, y_centre - x - 1, 2 * y + 1, 1, R, G, B); // 3
        drawBoxRGB_(x_centre - y, y_centre + x - 1, 2 * y + 1, 1, R, G, B); // 4

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
inline void drawDisc_(short x, short y, short rayon, Color col)
{
    drawDiscRGB_(x, y, rayon, col.components.R, col.components.G, col.components.B);
}
inline void drawDiscRGB(Disc *d, char R, char G, char B)
{
    drawDiscRGB_(d->x, d->y, d->radius, R, G, B);
}
inline void drawDisc(Disc *d, Color col)
{
    drawDiscRGB_(d->x, d->y, d->radius, col.components.R, col.components.G, col.components.B);
}
