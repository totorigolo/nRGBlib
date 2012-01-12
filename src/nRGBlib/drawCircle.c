#include <nGEO.h>

/// Dessine un cercle en couleur
void drawCircle_(int16_t x, int16_t y, int16_t radius, Color c)
{
    int16_t x2 = 0;
    int16_t y2 = radius; // On se place en haut du cercle
    int32_t m = 5 - 4 * radius; // Initialisation

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

        if (m > 0) // Choix du point
        {
            y2--;
            m -= 8 * y2;
        }
        x2++;
        m += 8 * x2 + 4;
    }
}
inline void drawCircle(Circle *c, Color col)
{
    drawCircle_(c->x, c->y, c->radius, col);
}
