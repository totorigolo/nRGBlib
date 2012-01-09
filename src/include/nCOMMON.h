#ifndef NCOMMON_H_INCLUDED
#define NCOMMON_H_INCLUDED

#include <os.h>

#define RGB(r, g, b) (uint16_t) ((r << 11) | (g << 5) | b)

typedef union Color {
    struct /**/components/**/ {
        int R : 5; // peu importe le type de r, g, b: le ": x" définit un bit field.
        int G : 6;
        int B : 5;
    } /**/components/**/;
    uint16_t raw;
} Color;

/// Récupère la valeur du pixel
Color getPixel(short x, short y);

/// Dessine un pixel en couleur
void setPixel(short x, short y, Color c);

/// Dessine l'écran entier avec la couleur
void clearScreen(Color c);


#endif // NCOMMON_H_INCLUDED
