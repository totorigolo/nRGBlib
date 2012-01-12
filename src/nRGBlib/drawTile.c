#include <nTILE.h>

// TODO: !!! uniquement un char pour les pixels

/// Dessine une tile de 8x8 pixels en couleurs agrandie *facteur (1 < facteur < infinie) aux positions données
///     \size supérieure à 1
void drawTile8Unicolor(int16_t x, int16_t y, int8_t size, Tile8Unicolor tile)
{
    int8_t i, j, f = size < 1 ? 1 : size;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if ((tile.data[i][0] << j) & 0x8) // 4 premiers pixels
            {
                drawBox_(x + (j * f), y + (i * f), f, f, tile.color);
            }
            if ((tile.data[i][1] << j) & 0x8) // 4 derniers pixels
            {
                drawBox_(x + ((j + 4) * f), y + (i * f), f, f, tile.color);
            }
        }
    }
}
void drawTile8Multicolors(int16_t x, int16_t y, int8_t size, Tile8Multicolors tile)
{
    int8_t i, j, f = size < 1 ? 1 : size;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if ((tile.data[i][0] << j) & 0x8) // 4 premiers pixels
            {
                drawBox_(x + (j * f), y + (i * f), f, f, RGB(tile.data[i][2 + j * 3], tile.data[i][3 + j * 3], tile.data[i][4 + j * 3]));
            }
            if ((tile.data[i][1] << j) & 0x8) // 4 derniers pixels
            {
                drawBox_(x + ((j + 4) * f), y + (i * f), f, f, RGB(tile.data[i][2 + (j + 4) * 3], tile.data[i][3 + (j + 4) * 3], tile.data[i][4 + (j + 4) * 3]));
            }
        }
    }
}
