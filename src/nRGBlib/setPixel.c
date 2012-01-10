#include <nCOMMON.h>
#include <libndls.h>
#include <os.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Dessine un pixel en couleur
void setPixel(short x, short y, Color *c)
{
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
        return;

    // Nspire non-CX
    if (!has_colors)
    {
        if (lcd_isincolor())
            lcd_ingray();

        char col = (c->R % 32 + c->G % 64 + c->B % 32) / 48; // 3 * 16
        unsigned char* p = (unsigned char*)(SCREEN_BASE_ADDRESS + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | col) : ((*p & 0x0F) | (col << 4));
    }
    // Nspire CX
    else
    {
        if (!lcd_isincolor())
            lcd_incolor();

        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr;
        ptr = scr_base + 2*(x + SCREEN_WIDTH * y);

        //                               Rouge 0-31        Vert 0-63       Bleu 0-31
        //*(volatile unsigned short*)ptr = (((c.R % 32) << 11) | ((c.G % 64) << 5) | (c.B % 32));
        *(volatile unsigned short*)ptr = c->raw;
    }
}
