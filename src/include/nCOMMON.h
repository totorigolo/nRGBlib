#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

#define newRGB(r, g, b) (Color) (uint16_t) (((r % 32) << 11) | ((g % 64) << 5) | (b % 32))
#define rawRGB(r, g, b) (((r % 32) << 11) | ((g % 64) << 5) | (b % 32))
#define RGB(r, g, b) (Color*) (uint16_t) (((r % 32) << 11) | ((g % 64) << 5) | (b % 32))

typedef union Color {
    struct {
        int R : 5; // peu importe le type de r, g, b: le ": x" d�finit un bit field.
        int G : 6;
        int B : 5;
    };
    uint16_t raw;
} Color;

/// R�cup�re la valeur du pixel
Color getPixel(short x, short y);

/// Dessine un pixel en couleur
void setPixel(short x, short y, Color *c);

/// Dessine l'�cran entier avec la couleur
void clearScreen(Color *c);


#endif // NCOMMON_H_INCLUDED
