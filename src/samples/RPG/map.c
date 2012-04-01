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

#include "map.h"

void loadFromFile(Map *map, char *filename)
{
    unsigned int i, x, y;
    FILE *f;
    char buffer[256];

    // Open file
    f = fopen(filename, "rb");
    if(!f) return;

    printf("Map infos:\n");

    /* Tileset */
    memset(&buffer, 0, sizeof(buffer));
    fread(&buffer, sizeof(char), 255, f); printf(" - Tileset's image path = %s\n", buffer);

    if (!loadImage(&map->tileset->img, buffer))
    {
        show_msgbox("Error!", "Failed to open tileset's image.");
        exit(0);
    }
    printf(" - Tileset's image succesfully loaded!\n");


    fread(&map->tileset->nbTiles, sizeof(unsigned int), 1, f); printf(" - nbTiles = %d\n", map->tileset->nbTiles);
    fread(&map->w, sizeof(unsigned int), 1, f); printf(" - map->w = %d\n", map->w);
    fread(&map->h, sizeof(unsigned int), 1, f); printf(" - map->h = %d\n", map->h);
    fread(&map->offset_x, sizeof(unsigned int), 1, f); map->offset_x *= CELL_SIZE; printf(" - offset_x = %d\n", map->offset_x);
    fread(&map->offset_y, sizeof(unsigned int), 1, f); map->offset_y *= CELL_SIZE; printf(" - offset_y = %d\n", map->offset_y);

    // Lit les infos sur le tileset
    map->tileset->tiles = calloc(map->tileset->nbTiles, sizeof(Tile));
    for (i = 0; i < map->tileset->nbTiles; i++)
    {
        fread(&map->tileset->tiles[i].x, sizeof(unsigned int), 1, f);
        fread(&map->tileset->tiles[i].y, sizeof(unsigned int), 1, f);
        fread(&map->tileset->tiles[i].collision, sizeof(unsigned char), 1, f);
        fread(&map->tileset->tiles[i].nextTile, sizeof(int), 1, f);
    }
    printf(" - Tiles succesfully loaded!\n");

    map->map = calloc(map->w * map->h, sizeof(uint32_t));
    for (y = 0; y < map->h; y++)
        for (x = 0; x < map->w; x++)
            fread(&map->map[x + y * map->w], sizeof(uint32_t), 1, f);
    printf("-> Map succesfully loaded!\n");

    fclose(f);
}
