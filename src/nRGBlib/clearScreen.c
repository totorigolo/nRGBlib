#include <libndls.h>
#include <nCOMMON.h>
#include <os.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Efface l'�cran entier avec la couleur
void clearScreen(Color c)
{
    int i, j;
    // 4 bpp
#if (__FAST_SETPIXEL__ == 1) // nCOMMON.h
    if (!has_colors)
#else
    if (!has_colors || ((*IO_LCD_CONTROL & 0b1110) != 0b1100)) // R5G6B5 - libndls - lcd_isincolor())
#endif
    {
        memset(SCREEN_BASE_ADDRESS, (((getBW(c)) << 4) | getBW(c)), (SCREEN_WIDTH * SCREEN_HEIGHT / 2));
    }
    // 16 bpp
    else
    {
        unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        unsigned char *ptr;
        for (ptr = scr_base; ptr < scr_base + (SCREEN_WIDTH * SCREEN_HEIGHT * 2); ptr += sizeof(uint16_t))
            *(uint16_t*)ptr = c;
    }
}
