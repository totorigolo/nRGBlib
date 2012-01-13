#include <libndls.h>
#include <nCOMMON.h>
#include <os.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Efface l'écran entier avec la couleur
void clearScreen(Color c)
{
    int i, j;
    // 4 bpp
    if (!has_colors)
    {
        for (i = 0; i < SCREEN_WIDTH; i++)
        {
            for (j = 0; j < SCREEN_HEIGHT; j++)
            {
                setPixel(i, j, c);
            }
        } // TODO: Optimiser
    }
    // 16 bpp
    else
    {
        unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        unsigned char *ptr;
        for (ptr = scr_base; ptr < scr_base + (SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint16_t)); ptr += sizeof(uint16_t))
            *(uint16_t*)ptr = c;
    }
}
