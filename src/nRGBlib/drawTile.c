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

#include <nTILE.h>

/// Draw a 8x8 tile in color resized to the given positions
//   - size >= 1
void drawTile8Unicolor(int16_t x, int16_t y, int8_t size, Tile8Unicolor tile, ScreenBuffer buffer[76800])
{
    int8_t i, j, f = size < 1 ? 1 : size;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if ((tile.data[i][0] << j) & 0x8) // 4 premiers pixels
            {
                drawBox_(x + (j * f), y + (i * f), f, f, tile.color, buffer);
            }
            if ((tile.data[i][1] << j) & 0x8) // 4 derniers pixels
            {
                drawBox_(x + ((j + 4) * f), y + (i * f), f, f, tile.color, buffer);
            }
        }
    }
}
/// Draw a 8x8 tile in colors resized to the given positions
//   - size >= 1
void drawTile8Multicolors(int16_t x, int16_t y, int8_t size, Tile8Multicolors tile, ScreenBuffer buffer[76800])
{
    int8_t i, j, f = size < 1 ? 1 : size;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if ((tile.data[i][0] << j) & 0x8) // 4 premiers pixels
            {
                drawBox_(x + (j * f), y + (i * f), f, f, RGB(tile.data[i][2 + j * 3], tile.data[i][3 + j * 3], tile.data[i][4 + j * 3]), buffer);
            }
            if ((tile.data[i][1] << j) & 0x8) // 4 derniers pixels
            {
                drawBox_(x + ((j + 4) * f), y + (i * f), f, f, RGB(tile.data[i][2 + (j + 4) * 3], tile.data[i][3 + (j + 4) * 3], tile.data[i][4 + (j + 4) * 3]), buffer);
            }
        }
    }
}
