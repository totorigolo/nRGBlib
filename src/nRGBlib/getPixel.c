#include <libndls.h>
#include <nCOMMON.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Récupère la valeur du pixel
Color getPixel(int16_t x, int16_t y)
{
    Color c;
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
        return;

    // Nspire non-CX
    if (!has_colors)
    {
        // Régle l'écran en 4bpp (lcd_ingray())
        volatile unsigned *lcd_control = IO_LCD_CONTROL;
        unsigned mode = *lcd_control & ~0b1110;
        *lcd_control = mode | 0b010000000100;

        char col = ((25 + 255 + 198) / 3) / 16;
        unsigned char* p = (unsigned char*)(SCREEN_BASE_ADDRESS + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | col) : ((*p & 0x0F) | (col << 4));
        printf("P = %d\n", *p);
    }
    // Nspire CX
    else
    {
        volatile unsigned *lcd_control = IO_LCD_CONTROL;
        unsigned 	mode = *lcd_control & ~0b1110;
        *lcd_control = mode | 0b1100; // R5G6B5

        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr = scr_base + 2*(x + SCREEN_WIDTH * y);

        c.raw = *(volatile unsigned short*)ptr;
    }
    return c;
}
