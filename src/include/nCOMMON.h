#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

#define rawRGB(r, g, b) (((r / 8) << 11) | ((g / 4) << 5) | (b / 8))
#define newRGB(r, g, b) (Color) (uint16_t) (((r / 8) << 11) | ((g / 4) << 5) | (b / 8))
#define RGB(r, g, b) (Color*) (uint16_t) (((r / 8) << 11) | ((g / 4) << 5) | (b / 8))

typedef union Color {
    struct {
        int R : 5; // peu importe le type de r, g, b: le ": x" définit un bit field.
        int G : 6;
        int B : 5;
    };
    uint16_t raw;
} Color;

/// Récupère la valeur du pixel
Color getPixel(short x, short y);

/// Dessine un pixel en couleur
void setPixel(short x, short y, Color *c);

/// Dessine l'écran entier avec la couleur
void clearScreen(Color *c);


#endif // NCOMMON_H_INCLUDED
