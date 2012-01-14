#include <nGEO.h>

/// Draw a disc in color
void drawDisc_(int16_t x, int16_t y, int16_t radius, Color c)
{
    int16_t x2 = 0;
    int16_t y2 = radius;
    int32_t d = 3 - (2 * radius);

    while (y2 >= x2)
    {
        drawBox_(x - x2, y - y2, 2 * x2 + 1, 1, c);
        drawBox_(x - x2, y + y2, 2 * x2 + 1, 1, c);
        drawBox_(x - y2, y - x2, 2 * y2 + 1, 1, c);
        drawBox_(x - y2, y + x2, 2 * y2 + 1, 1, c);

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
inline void drawDisc(Disc *d, Color c)
{
    drawDisc_(d->x, d->y, d->radius, c);
}
