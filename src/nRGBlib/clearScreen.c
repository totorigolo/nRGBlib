#include <libndls.h>
#include <nCOMMON.h>
#include <os.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Efface l'écran entier avec la couleur
void clearScreen(Color c)
{
    int i, j;
    // Nspire non-CX
    if (!has_colors)
    {
        if (lcd_isincolor())
            lcd_ingray();

        for (i = 0; i < SCREEN_WIDTH; i++)
        {
            for (j = 0; j < SCREEN_HEIGHT; j++)
            {
                setPixel(i, j, c);
            }
        }
        // TODO: Optimiser
    }
    // Nspire CX
    else
    {
        if (!lcd_isincolor())
            lcd_incolor();

        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr;
        //unsigned scr_size = SCREEN_BYTES_SIZE;

        for (ptr = scr_base; ptr < scr_base + (SCREEN_WIDTH * SCREEN_HEIGHT * 2); ptr += 2)
        //    *(volatile unsigned short*)ptr = ((R / 8) << 11) | ((G / 4) << 5) | (B / 8);
            *(volatile unsigned short*)ptr = c.raw;
    }
}
