/****************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The Original Code is nRGBlib code.
 *
 * The Initial Developer of the Original Code is Thomas LACROIX aka totorigolo
 * <toto.rigolo@free.fr>.
 * Portions created by the Initial Developer are Copyright (C) 2011-2012
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 ****************************************************************************/

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <os.h>
#include <nIMAGE.h>

#define CELL_SIZE 32
#define NB_TILES_X 5
#define NB_TILES_Y 4

typedef struct Tile {
    uint16_t x;
    uint16_t y;
    uint8_t collision;
    int32_t nextTile;
} Tile;

typedef struct Tileset {
    Image img;
    uint16_t nbTiles;
    Tile *tiles;
} Tileset;

typedef struct Map {
    uint16_t w;
    uint16_t h;
    uint32_t *map;
    Tileset *tileset;
    uint16_t offset_x;
    uint16_t offset_y;
} Map;

void loadFromFile(Map *map, char *filename);

#endif // MAP_H_INCLUDED
