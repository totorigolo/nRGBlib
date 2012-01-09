#include <nGUI.h>

/// Dessine une lettre aux position données en changeant la couleur de fond
void drawCharBckgRGB(short x, short y, char ch, char size, char R, char G, char B, char Rb, char Gb, char Bb)
{
    short i, j, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBoxRGB_(x + (j * f), y + (i * f), f, f, R, G, B);
            }
            else
            {
                drawBoxRGB_(x + (j * f), y + (i * f), f, f, Rb, Gb, Bb);
            }
        }
    }
}
inline void drawCharBckg(short x, short y, char ch, char size, Color colT, Color colB)
{
    drawCharBckgRGB(x, y, ch, size, colT.components.R, colT.components.G, colT.components.B, colB.components.R, colB.components.G, colB.components.B);
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
                drawBoxRGB_(x + (j * f), y + (i * f), f, f, R, G, B);
            }
        }
    }
}
inline void drawChar(short x, short y, char ch, char size, Color col)
{
    drawCharRGB(x, y, ch, size, col.components.R, col.components.G, col.components.B);
}
