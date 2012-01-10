#include <nGUI.h>

/// Dessine une lettre aux position données en changeant la couleur de fond
void drawCharBckg(short x, short y, char ch, char size, Color *cT, Color *cB)
{
    short i, j, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBox_(x + (j * f), y + (i * f), f, f, cT);
            }
            else
            {
                drawBox_(x + (j * f), y + (i * f), f, f, cB);
            }
        }
    }
}

/// Dessine une lettre aux position données
void drawChar(short x, short y, char ch, char size, Color *c)
{
    short i, j, f;
    f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBox_(x + (j * f), y + (i * f), f, f, c);
            }
        }
    }
}
