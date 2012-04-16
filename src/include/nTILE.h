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

/// Draw a 8x8 tile in color(s) resized to the given positions
//   - size >= 1
void drawTile8Unicolor(int16_t x, int16_t y, int8_t size, Tile8Unicolor tile, ScreenBuffer buffer);
void drawTile8Multicolors(int16_t x, int16_t y, int8_t size, Tile8Multicolors tile, ScreenBuffer buffer);

#endif // NTILE_H_INCLUDED
