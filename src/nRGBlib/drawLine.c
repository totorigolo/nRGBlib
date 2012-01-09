#include <nGEO.h>

/// Dessine une ligne quelconque en couleurs
void drawLine_(short x1, short y1, short x2, short y2, Color c)
{
    int d, dx, dy, aincr, bincr, xincr, yincr, x, y;
printf("l1\n");
    if (abs(x2 - x1) < abs(y2 - y1)) // Parcours par l'axe vertical
    {
        if (y1 > y2)
        {
            echangerEntiers(&x1, &x2);
            echangerEntiers(&y1, &y2);
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
printf("l2\n");
    }
    else // Parcours l'axe horizontal
    {
        if (x1 > x2)
        {
            echangerEntiers(&x1, &x2);
            echangerEntiers(&y1, &y2);
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
printf("l3\n");
    }
printf("l4\n");
}
inline void drawLine(Line *l, Color c)
{
    drawLine_(l->x1, l->y1, l->x2, l->y2, c);
}
