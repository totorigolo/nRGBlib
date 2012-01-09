#include <nGEO.h>

/// Dessine un triangle vide en couleur
void drawTriangleRGB_(short x1, short y1, short x2, short y2, short x3, short y3, char R, char G, char B)
{
    drawLineRGB_(x1, y1, x2, y2, R, G, B);
    drawLineRGB_(x2, y2, x3, y3, R, G, B);
    drawLineRGB_(x1, y1, x3, y3, R, G, B);
}
inline void drawTriangle_(short x1, short y1, short x2, short y2, short x3, short y3, Color col)
{
    drawTriangleRGB_(x1, y1, x2, y2, x3, y3, col.components.R, col.components.G, col.components.B);
}
inline void drawTriangleRGB(Triangle *t, char R, char G, char B)
{
    drawTriangleRGB_(t->x1, t->y1, t->x2, t->y2, t->x3, t->y3, R, G, B);
}
inline void drawTriangle(Triangle *t, Color col)
{
    drawTriangleRGB_(t->x1, t->y1, t->x2, t->y2, t->x3, t->y3, col.components.R, col.components.G, col.components.B);
}
