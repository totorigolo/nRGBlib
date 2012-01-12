#include <nGEO.h>

/// Dessine un triangle vide en couleur
void drawTriangle_(short x1, short y1, short x2, short y2, short x3, short y3, Color c)
{
    drawLine_(x1, y1, x2, y2, c);
    drawLine_(x2, y2, x3, y3, c);
    drawLine_(x1, y1, x3, y3, c);
}
inline void drawTriangle(Triangle *t, Color c)
{
    drawTriangle_(t->x1, t->y1, t->x2, t->y2, t->x3, t->y3, c);
}
