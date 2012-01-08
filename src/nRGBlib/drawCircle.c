#include <nGEO.h>

/// Dessine un cercle en couleur
void drawCircleRGB(short x_centre, short y_centre, short rayon, char R, char G, char B)
{
    short x = 0;
    short y = rayon; // On se place en haut du cercle
    short m = 5 - 4 * rayon; // Initialisation

    while (x <= y) // Tant qu'on est dans le second octant
    {
        setPixelRGB( x + x_centre,  y + y_centre, R, G, B);
        setPixelRGB( y + x_centre,  x + y_centre, R, G, B);
        setPixelRGB(-x + x_centre,  y + y_centre, R, G, B); // 2
        setPixelRGB(-y + x_centre,  x + y_centre, R, G, B); // 4
        setPixelRGB( x + x_centre, -y + y_centre, R, G, B);
        setPixelRGB( y + x_centre, -x + y_centre, R, G, B);
        setPixelRGB(-x + x_centre, -y + y_centre, R, G, B); // 1
        setPixelRGB(-y + x_centre, -x + y_centre, R, G, B); // 3

        if (m > 0) // Choix du point F
        {
            y--;
            m -= 8 * y;
        }
        x++;
        m += 8 * x + 4;
    }
}
void drawCircleColor(short x, short y, short rayon, Color col)
{
    drawCircleRGB(x, y, rayon, col.R, col.G, col.B);
}
