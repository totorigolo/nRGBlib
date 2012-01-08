#include <nGEO.h>
#include <libndls.h>
#include <os.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Dessine trois bandes RGB qui font chacunes 1 / 3 de l'écran
void RGBstrips()
{
    // Nspire non-CX
    if (!has_colors)
    {
        if (lcd_isincolor())
            lcd_ingray();

        // TODO: RGBstrips pour non-CX
    }
    // Nspire CX
    else
    {
        if (!lcd_isincolor())
            lcd_incolor();

        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr;
        //unsigned scr_size = SCREEN_BYTES_SIZE;

        for (ptr = scr_base; ptr < scr_base + SCREEN_BYTES_SIZE / 3; ptr += 2)
            *(volatile unsigned short*)ptr = 0b1111100000000000;

        for (; ptr < scr_base + SCREEN_BYTES_SIZE * 2 / 3; ptr += 2)
            *(volatile unsigned short*)ptr = 0b0000011111100000;

        for (; ptr < scr_base + SCREEN_BYTES_SIZE; ptr += 2)
            *(volatile unsigned short*)ptr = 0b0000000000011111;
        }
}
