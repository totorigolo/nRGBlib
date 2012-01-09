#include <nGEO.h>

/// Dessine un cercle en couleur
void drawCircleRGB_(short x_centre, short y_centre, short rayon, char R, char G, char B)
{
    short x = 0;
    short y = rayon; // On se place en haut du cercle
    short m = 5 - 4 * rayon; // Initialisation

    while (x <= y) // Tant qu'on est dans le second octant
    {
        setPixel( x + x_centre,  y + y_centre, RGB(R, G, B));
        setPixel( y + x_centre,  x + y_centre, RGB(R, G, B));
        setPixel(-x + x_centre,  y + y_centre, RGB(R, G, B));
        setPixel(-y + x_centre,  x + y_centre, RGB(R, G, B));
        setPixel( x + x_centre, -y + y_centre, RGB(R, G, B));
        setPixel( y + x_centre, -x + y_centre, RGB(R, G, B));
        setPixel(-x + x_centre, -y + y_centre, RGB(R, G, B));
        setPixel(-y + x_centre, -x + y_centre, RGB(R, G, B));

        if (m > 0) // Choix du point F
        {
            y--;
            m -= 8 * y;
        }
        x++;
        m += 8 * x + 4;
    }
}
inline void drawCircle_(short x, short y, short rayon, Color col)
{
    drawCircleRGB_(x, y, rayon, col.components.R, col.components.G, col.components.B);
}
inline void drawCircleRGB(Circle *c, char R, char G, char B)
{
    drawCircleRGB_(c->x, c->y, c->radius, R, G, B);
}
inline void drawCircle(Circle *c, Color col)
{
    drawCircleRGB_(c->x, c->y, c->radius, col.components.R, col.components.G, col.components.B);
}
