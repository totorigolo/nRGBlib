#include <nGEO.h>

/// Draw an empty triangle to the given positions
void drawTriangle_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3, Color c)
{
    drawLine_(x1, y1, x2, y2, c);
    drawLine_(x2, y2, x3, y3, c);
    drawLine_(x1, y1, x3, y3, c);
}
inline void drawTriangle(Triangle *t, Color c)
{
    drawTriangle_(t->x1, t->y1, t->x2, t->y2, t->x3, t->y3, c);
}
