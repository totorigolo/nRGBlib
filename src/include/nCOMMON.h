#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

typedef union Color {
    struct {
        uint8_t R : 5; // peu importe le type de r, g, b: le ": x" définit un bit field.
        uint8_t G : 6;
        uint8_t B : 5;
    };
    uint16_t raw;
} Color;

#define rawRGB(r, g, b) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))
#define RGB(r, g, b) (Color) (uint16_t) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))

/// Récupère la valeur du pixel
Color getPixel(int16_t x, int16_t y);

/// Dessine un pixel en couleur
void setPixel(int16_t x, int16_t y, Color c);

/// Dessine l'écran entier avec la couleur
void clearScreen(Color c);

#endif // NCOMMON_H_INCLUDED
