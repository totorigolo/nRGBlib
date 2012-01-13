#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

typedef uint16_t Color;

#define RGB(r, g, b) (Color) (uint16_t) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))
#define getR(c) (((c & 0xF800) >> 11) / 2)
#define getG(c) (((c & 0x7E0) >> 5) / 4)
#define getB(c) ((c & 0x1F) / 2)

/// Dessine un pixel en couleur
void setPixel(int16_t x, int16_t y, Color c);

/// Dessine l'écran entier avec la couleur
void clearScreen(Color c);

#endif // NCOMMON_H_INCLUDED
