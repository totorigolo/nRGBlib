#ifndef NTILE_H_INCLUDED
#define NTILE_H_INCLUDED

#include "nCOMMON.h"

typedef struct Tile8Multicolors Tile8Multicolors;
struct Tile8Multicolors
{
    char data[8][2 + 8 * 3];
};

typedef struct Tile8Unicolor Tile8Unicolor;
struct Tile8Unicolor
{
    Color color;
    char data[8][2];
};

typedef struct Tile16Multicolors Tile16Multicolors;
struct Tile16Multicolors
{
    char data[16][2 + 16 * 3];
};

typedef struct Tile16Unicolor Tile16Unicolor;
struct Tile16Unicolor
{
    Color color;
    char data[16][2];
};

/// Dessine une tile de 8x8 pixels en couleurs aux positions données
/// \size supérieure à 1; 1 = taille normale
void drawTile8Unicolor(int16_t x, int16_t y, int8_t size, Tile8Unicolor tile);
void drawTile8Multicolors(int16_t x, int16_t y, int8_t size, Tile8Multicolors tile);


#endif // NTILE_H_INCLUDED
