#include <nGEO.h>

/// Draw a line in color
//    - Note that for a vertical or horizontal line, utilisation of drawBox is faster
void drawLine_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, Color c)
{
    int16_t d, dx, dy, aincr, bincr, xincr, yincr, x, y, tmp;

    if (abs(x2 - x1) < abs(y2 - y1)) // Parcours par l'axe vertical
    {
        if (y1 > y2) // Echange les nombres
        {
            tmp = x1; x1 = x2; x2 = tmp;
            tmp = y1; y1 = y2; y2 = tmp;
        }

        xincr = x2 > x1 ? 1 : -1;
        dy = y2 - y1;
        dx = abs(x2 - x1);
        d = 2 * dx - dy;
        aincr = 2 * (dx - dy);
        bincr = 2 * dx;
        x = x1;
        y = y1;

        setPixel(x, y, c);

        for (y = y1+1; y <= y2; ++y)
        {
            if (d >= 0)
            {
                x += xincr;
                d += aincr;
            }
            else
                d += bincr;

            setPixel(x, y, c);
        }
    }
    else // Parcours l'axe horizontal
    {
        if (x1 > x2) // Echange les nombres
        {
            tmp = x1; x1 = x2; x2 = tmp;
            tmp = y1; y1 = y2; y2 = tmp;
        }

        yincr = y2 > y1 ? 1 : -1;
        dx = x2 - x1;
        dy = abs(y2 - y1);
        d = 2 * dy - dx;
        aincr = 2 * (dy - dx);
        bincr = 2 * dy;
        x = x1;
        y = y1;

        setPixel(x, y, c);

        for (x = x1+1; x <= x2; ++x)
        {
            if (d >= 0)
            {
                y += yincr;
                d += aincr;
            }
            else
                d += bincr;
            setPixel(x, y, c);
        }
    }
}
inline void drawLine(Line *l, Color c)
{
    drawLine_(l->x1, l->y1, l->x2, l->y2, c);
}
