#include <nGEO.h>

/// Dessine une ligne quelconque en couleurs
void drawLineRGB(int x1, int y1, int x2, int y2, char R, char G, char B)
{
    int d, dx, dy, aincr, bincr, xincr, yincr, x, y;

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

        setPixelRGB(x, y, R, G, B);

        for (y = y1+1; y <= y2; ++y)
        {
            if (d >= 0)
            {
                x += xincr;
                d += aincr;
            }
            else
                d += bincr;

            setPixelRGB(x, y, R, G, B);
        }
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

        setPixelRGB(x, y, R, G, B);

        for (x = x1+1; x <= x2; ++x)
        {
            if (d >= 0)
            {
                y += yincr;
                d += aincr;
            }
            else
                d += bincr;
            setPixelRGB(x, y, R, G, B);
        }
    }
}
void drawLineColor(int x1, int y1, int x2, int y2, Color col)
{
    drawLineRGB(x1, y1, x2, y2, col.R, col.G, col.B);
}
