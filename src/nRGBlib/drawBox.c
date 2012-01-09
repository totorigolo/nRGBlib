#include <nGEO.h>
#include <os.h>

/// Dessine un rectangle en RGB
void drawBoxRGB_(short x, short y, short w, short h, char R, char G, char B)
{
    short i, j;
    for (i = x; i < (x + w); i++)
    {
        for (j = y; j < (y + h); j++)
        {
            setPixel(i, j, RGB(R, G, B));
        }
    }
}
inline void drawBox_(short x, short y, short w, short h, Color col)
{
    drawBoxRGB_(x, y, w, h, col.components.R, col.components.G, col.components.B);
}
inline void drawBoxRGB(Box *box, char R, char G, char B)
{
    drawBoxRGB_(box->x, box->y, box->w, box->h, R, G, B);
}
inline void drawBox(Box *box, Color col)
{
    drawBoxRGB_(box->x, box->y, box->w, box->h, col.components.R, col.components.G, col.components.B);
}

inline void drawSquareRGB_(short x, short y, short c, char R, char G, char B)
{
    drawBoxRGB_(x, y, c, c, R, G, B);
}
inline void drawSquare_(short x, short y, short c, Color col)
{
    drawBoxRGB_(x, y, c, c, col.components.R, col.components.G, col.components.B);
}
inline void drawSquareRGB(Square *s, char R, char G, char B)
{
    drawBoxRGB_(s->x, s->y, s->c, s->c, R, G, B);
}
inline void drawSquare(Square *s, Color col)
{
    drawBoxRGB_(s->x, s->y, s->c, s->c, col.components.R, col.components.G, col.components.B);
}
