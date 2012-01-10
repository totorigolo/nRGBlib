#include <nGEO.h>

/// Dessine un disque en couleur
void drawDisc_(short x, short y, short radius, Color *c)
{ // TODO: Vérifier si le dessin n'est pas trop grand
    short x2 = 0;
    short y2 = radius;
    short d = 3 - (2 * radius);

    while (y2 >= x2)
    {
        drawBox_(x - x2, y - y2 - 1, 2 * x2 + 1, 1, c);
        drawBox_(x - x2, y + y2 - 1, 2 * x2 + 1, 1, c);
        drawBox_(x - y2, y - x2 - 1, 2 * y2 + 1, 1, c);
        drawBox_(x - y2, y + x2 - 1, 2 * y2 + 1, 1, c);

        if (d < 0)
            d += (4 * x2) + 6;
        else
        {
            d += 4 * (x2 - y2) + 10;
            y2--;
        }
        x2++;
    }
}
inline void drawDisc(Disc *d, Color *c)
{
    drawDisc_(d->x, d->y, d->radius, c);
}
