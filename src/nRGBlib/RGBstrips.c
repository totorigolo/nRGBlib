#include <nGEO.h>
#include <os.h>

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Draw three red, green and blue strips
void RGBstrips()
{
    // 4 bpp
#if (__FAST_SETPIXEL__ == 1) // nCOMMON.h
    if (!has_colors)
#else
    if (!has_colors || ((*IO_LCD_CONTROL & 0b1110) != 0b1100)) // R5G6B5 - libndls - lcd_isincolor())
#endif
    {
        // TODO: RGBstrips pour non-CX
    }
    // 16 bpp
    else
    {
        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr;

        for (ptr = scr_base; ptr < scr_base + SCREEN_BYTES_SIZE / 3; ptr += 2)
            *(volatile unsigned short*)ptr = 0b1111100000000000;

        for (; ptr < scr_base + SCREEN_BYTES_SIZE * 2 / 3; ptr += 2)
            *(volatile unsigned short*)ptr = 0b0000011111100000;

        for (; ptr < scr_base + SCREEN_BYTES_SIZE; ptr += 2)
            *(volatile unsigned short*)ptr = 0b0000000000011111;
        }
}
