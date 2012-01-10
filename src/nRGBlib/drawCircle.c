#include <nGEO.h>

/// Dessine un cercle en couleur
void drawCircle_(short x, short y, short radius, Color *c)
{
    short x2 = 0;
    short y2 = radius; // On se place en haut du cercle
    short m = 5 - 4 * radius; // Initialisation

    while (x2 <= y2) // Tant qu'on est dans le second octant
    {
        setPixel( x2 + x,  y2 + y, c);
        setPixel( y2 + x,  x2 + y, c);
        setPixel(-x2 + x,  y2 + y, c);
        setPixel(-y2 + x,  x2 + y, c);
        setPixel( x2 + x, -y2 + y, c);
        setPixel( y2 + x, -x2 + y, c);
        setPixel(-x2 + x, -y2 + y, c);
        setPixel(-y2 + x, -x2 + y, c);

        if (m > 0) // Choix du point F
        {
            y2--;
            m -= 8 * y2;
        }
        x2++;
        m += 8 * x2 + 4;
    }
}
inline void drawCircle(Circle *c, Color *col)
{
    drawCircle_(c->x, c->y, c->radius, col);
}
