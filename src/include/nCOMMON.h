#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

/*/#define rawRGB(r, g, b) (((r / 8) << 11) | ((g / 4) << 5) | (b / 8))
//#define newRGB(r, g, b) (Color) (uint16_t) (((r / 8) << 11) | ((g / 4) << 5) | (b / 8))
//#define RGB(r, g, b) (Color*) (uint16_t) (((r / 8) << 11) | ((g / 4) << 5) | (b / 8))*/

typedef union Color {
    struct {
        uint8_t R : 5; // peu importe le type de r, g, b: le ": x" d�finit un bit field.
        uint8_t G : 6;
        uint8_t B : 5;
    };
    uint16_t raw;
} Color;

//typedef uint16_t Color;
#define rawRGB(r, g, b) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))
//#define newRGB(r, g, b) (Color) (uint16_t) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))
#define RGB(r, g, b) (Color) (uint16_t) (((((uint8_t)(r)) / 8) << 11) | ((((uint8_t)(g)) / 4) << 5) | (((uint8_t)(b)) / 8))

/// R�cup�re la valeur du pixel
Color getPixel(short x, short y);

/// Dessine un pixel en couleur
void setPixel(short x, short y, Color c);

/// Dessine l'�cran entier avec la couleur
void clearScreen(Color c);


#endif // NCOMMON_H_INCLUDED
