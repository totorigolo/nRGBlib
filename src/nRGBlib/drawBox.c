#include <nGEO.h>
#include <os.h>

/// Dessine un rectangle en RGB
void drawBox2DRGB(short x, short y, short w, short h, char R, char G, char B)
{
    short i, j;
    for (i = x; i < (x + w); i++)
    {
        for (j = y; j < (y + h); j++)
        {
            setPixelRGB(i, j, R, G, B);
        }
    }
}
inline void drawSquareRGB(short x, short y, short c, char R, char G, char B)
{
    drawBox2DRGB(x, y, c, c, R, G, B);
}
inline void drawBoxRGB(Box box, char R, char G, char B)
{
    drawBox2DRGB(box.x, box.y, box.w, box.h, R, G, B);
}
inline void drawBox2DColor(short x, short y, short w, short h, Color col)
{
    drawBox2DRGB(x, y, w, h, col.R, col.G, col.B);
}
inline void drawSquareColor(short x, short y, short c, Color col)
{
    drawSquareRGB(x, y, c, col.R, col.G, col.B);
}
inline void drawBoxColor(Box box, Color col)
{
    drawBox2DRGB(box.x, box.y, box.w, box.h, col.R, col.G, col.B);
}
