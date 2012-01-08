#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include "nRGBlib.h"

Tile8Unicolor tile_bonhommeU = {255,   0, 0, {
    {0b0011, 0b1100},
    {0b0011, 0b1100},
    {0b0001, 0b1000},
    {0b1111, 0b1111},
    {0b1011, 0b1101},
    {0b1011, 0b1101},
    {0b0010, 0b0100},
    {0b0110, 0b0110}
} };

Tile8Multicolors tile_bonhommeM = { {
    {0b0011, 0b1100, /**/ 0,   0,   0, /**/ 0,   0,   0, /**/ 255,   0,   0, /**/ 255,   0,   0, /**/ 255,   0,   0, /**/ 255,   0,   0, /**/   0,   0,   0, /**/   0,  0,   0},
    {0b0011, 0b1100, /**/ 0,   0,   0, /**/ 0,   0,   0, /**/ 255,   0,   0, /**/ 255,   0,   0, /**/ 255,   0,   0, /**/ 255,   0,   0, /**/   0,   0,   0, /**/   0,  0,   0},
    {0b0001, 0b1000, /**/ 0,   0,   0, /**/ 0,   0,   0, /**/   0,   0,   0, /**/ 255,  80,   0, /**/ 255,  80,   0, /**/   0,   0,   0, /**/   0,   0,   0, /**/   0,  0,   0},
    {0b1111, 0b1111, /**/ 140, 0, 255, /**/ 140, 0, 255, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 140,   0, 255, /**/ 140,  0, 255},
    {0b1011, 0b1101, /**/ 140, 0, 255, /**/ 0,   0,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/   0,   0,   0, /**/ 140,  0, 255},
    {0b1011, 0b1101, /**/ 140, 0, 255, /**/ 0,   0,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/ 255, 255,   0, /**/   0,   0,   0, /**/ 140,  0, 255},
    {0b0010, 0b0100, /**/ 0,   0,   0, /**/ 0,   0,   0, /**/   0, 255, 255, /**/   0,   0,   0, /**/   0,   0,   0, /**/   0, 255, 255, /**/   0,   0,   0, /**/   0,  0,   0},
    {0b0110, 0b0110, /**/ 0,   0,   0, /**/ 0, 255, 255, /**/   0, 255, 255, /**/   0,   0,   0, /**/   0,   0,   0, /**/   0, 255, 255, /**/   0, 255, 255, /**/   0,  0,   0}
} };

#endif // TILESET_H_INCLUDED
