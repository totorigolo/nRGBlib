#include <nCOMMON.h>
#include <libndls.h>
#include <os.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Dessine un pixel en couleur
void setPixel(int16_t x, int16_t y, Color c)
{
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;

    // 4 bpp
#if (__FAST_SETPIXEL__ == 1) // nCOMMON.h
    if (!has_colors)
#else
    if (!has_colors || ((*IO_LCD_CONTROL & 0b1110) != 0b1100)) // R5G6B5 - libndls - lcd_isincolor())
#endif
    {
        unsigned char* p = (unsigned char*)(SCREEN_BASE_ADDRESS + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | getBW(c)) : ((*p & 0x0F) | (getBW(c) << 4));
    }
    // 16 bpp
    else
    {
        unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        unsigned char *ptr;
        ptr = scr_base + sizeof(uint16_t) * (x + SCREEN_WIDTH * y);
        *(unsigned short*)ptr = c;
    }
}
