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
    if (!has_colors)// || ((*IO_LCD_CONTROL & 0b1110) != 0b1100)) // R5G6B5 - libndls - lcd_isincolor())
    {
        //uint8_t col = ((((c.raw & 0xF800) >> 11) / 2) + (((c.raw & 0x7E0) >> 5) / 4) + ((c.raw & 0x1F) / 2)) / 3;
        uint8_t col = (getR(c) + getG(c) + getB(c)) / 3;

        unsigned char* p = (unsigned char*)(SCREEN_BASE_ADDRESS + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | col) : ((*p & 0x0F) | (col << 4));
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
