#include <nCOMMON.h>

// Voir le lien pour la couleur (mode R5G6B5) :
//   -> See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer

/// Récupère la valeur du pixel
Pixel getPixel(short x, short y)
{
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
        return;

    // Nspire non-CX
    if (!has_colors)
    {
        if (lcd_isincolor())
            lcd_ingray();

        char col = ((25 + 255 + 198) / 3) / 16;
        unsigned char* p = (unsigned char*)(SCREEN_BASE_ADDRESS + ((x >> 1) + (y << 7) + (y << 5)));
        *p = (x & 1) ? ((*p & 0xF0) | col) : ((*p & 0x0F) | (col << 4));
        printf("P = %d\n", *p);
    }
    // Nspire CX
    else
    {
        if (!lcd_isincolor())
            lcd_incolor();

        volatile unsigned char *scr_base = SCREEN_BASE_ADDRESS;
        volatile unsigned char *ptr = scr_base + 2*(x + SCREEN_WIDTH * y);

        char R = *(ptr + 11) * 8;
        char G = *(ptr + 5) * 4;
        char B = *ptr * 8;

        printf("R = %d\n", R);
        printf("G = %d\n", G);
        printf("B = %d\n", B);

        //                               Rouge 0-31        Vert 0-63       Bleu 0-31
        //*(volatile unsigned short*)ptr = ((R / 8) << 11) | ((G / 4) << 5) | (B / 8);
    }
}
