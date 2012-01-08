#include <nGEO.h>

/// Dessine un triangle vide en couleur
void drawTriangleRGB(short x1, short y1, short x2, short y2, short x3, short y3, char R, char G, char B)
{
    drawLineRGB(x1, y1, x2, y2, R, G, B);
    drawLineRGB(x2, y2, x3, y3, R, G, B);
    drawLineRGB(x1, y1, x3, y3, R, G, B);
}
void drawTriangleColor(short x1, short y1, short x2, short y2, short x3, short y3, Color col)
{
    drawTriangleRGB(x1, y1, x2, y2, x3, y3, col.R, col.G, col.B);
}
