#include <nGUI.h>

/// Dessine une lettre aux position données en changeant la couleur de fond
void drawCharRGBFond(short x, short y, char ch, char size, char R, char G, char B, char Rf, char Gf, char Bf)
{
    short i, j, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBox2DRGB(x + (j * f), y + (i * f), f, f, R, G, B);
            }
            else
            {
                drawBox2DRGB(x + (j * f), y + (i * f), f, f, Rf, Gf, Bf);
            }
        }
    }
}
inline void drawCharColorFond(short x, short y, char ch, char size, Color colT, Color colF)
{
    drawCharRGBFond(x, y, ch, size, colT.R, colT.G, colT.B, colF.R, colF.G, colF.B);
}
inline void drawCharFond(short x, short y, char ch, char size)
{
    drawCharRGBFond(x, y, ch, size, 0, 0, 0, 255, 255, 255);
}

/// Dessine une lettre aux position données
void drawCharRGB(short x, short y, char ch, char size, char R, char G, char B)
{
    short i, j, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBox2DRGB(x + (j * f), y + (i * f), f, f, R, G, B);
            }
        }
    }
}
inline void drawCharColor(short x, short y, char ch, char size, Color col)
{
    drawCharRGB(x, y, ch, size, col.R, col.G, col.B);
}
inline void drawChar(short x, short y, char ch, char size)
{
    drawCharRGB(x, y, ch, size, 0, 0, 0);
}
