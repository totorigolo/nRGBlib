#include <nGEO.h>
#include <os.h>

/// Dessine un rectangle en RGB
void drawBox_(short x, short y, short w, short h, Color *c)
{
    short i, j;
    for (i = x; i < (x + w); i++)
    {
        for (j = y; j < (y + h); j++)
        {
            setPixel(i, j, c);
        }
    }
}
inline void drawBox(Box *box, Color *c)
{
    drawBox_(box->x, box->y, box->w, box->h, c);
}

inline void drawSquare_(short x, short y, short side, Color *c)
{
    drawBox_(x, y, side, side, c);
}
inline void drawSquare(Square *s, Color *c)
{
    drawBox_(s->x, s->y, s->side, s->side, c);
}
