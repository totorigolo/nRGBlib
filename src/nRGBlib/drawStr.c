#include <nGUI.h>
#include <os.h>

/// Write a text to the given position and change background color
//    - endl is a boolean which define if the line break is allowed
void drawStrBckg(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color cT, Color cB)
{
    int16_t i;
    int8_t f = size < 1 ? 1 : size;
    for (i = 0; i < strlen(str); i++)
    {
        // If the current character is '\n'
        if (str[i] == '\n') // 0x0A = '\n'
        {
            // If the line break is allowed
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Else, consider this like a space
            else
            {
                x += (CHAR_WIDTH * f);
            }
        }
        else
        {
            drawCharBckg(x, y, str[i], f, cT, cB);
            x += (CHAR_WIDTH * f);
        }
        // If you go beyond the screen
        if (x > SCREEN_WIDTH - CHAR_WIDTH)
        {
            // Wrap on, we jump
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Otherwise we stop the line
            else
                break;
        }
    }
}

/// Write a text to the given position
//    - endl is a boolean which define if the line break is allowed
void drawStr(int16_t x, int16_t y, char* str, int8_t size, int8_t endl, Color c)
{
    int16_t i;
    int8_t f = size < 1 ? 1 : size;
    for (i = 0; i < strlen(str); i++)
    {
        // If the current character is '\n'
        if (str[i] == '\n') // 0x0A = '\n'
        {
            // If the line break is allowed
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Else, consider this like a space
            else
            {
                x += (CHAR_WIDTH * f);
            }
        }
        else
        {
            drawChar(x, y, str[i], f, c);
            x += (CHAR_WIDTH * f);
        }
        // If you go beyond the screen
        if (x >= SCREEN_WIDTH - CHAR_WIDTH)
        {
            // Wrap on, we jump
            if (endl)
            {
                x = 0;
                y += (CHAR_HEIGHT * f);
            }
            // Otherwise we stop the line
            else
                break;
        }
    }
}
