#include <nGUI.h>

/// Draw a letter to the given position and change the background color
void drawCharBckg(int16_t x, int16_t y, char ch, int8_t size, Color cT, Color cB)
{
    int32_t i, j;
    int8_t f = size < 1 ? 1 : size;
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

/// Draw a letter to the given position
void drawChar(int16_t x, int16_t y, char ch, int8_t size, Color c)
{
    int32_t i, j;
    int8_t f = size < 1 ? 1 : size;
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
