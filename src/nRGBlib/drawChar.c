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

#include <nGUI.h>

/// Draw a letter to the given position and change the background color
void drawCharBckg(int16_t x, int16_t y, char ch, int8_t size, Color cT, Color cB, ScreenBuffer buffer)
{
    int32_t i, j;
    int8_t f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBox_(x + (j * f), y + (i * f), f, f, cT, buffer);
            }
            else
            {
                drawBox_(x + (j * f), y + (i * f), f, f, cB, buffer);
            }
        }
    }
}

/// Draw a letter to the given position
void drawChar(int16_t x, int16_t y, char ch, int8_t size, Color c, ScreenBuffer buffer)
{
    int32_t i, j;
    int8_t f = size < 1 ? 1 : size;
    for (i = 0; i < CHAR_HEIGHT; i++)
    {
        for (j = 0; j < CHAR_WIDTH; j++)
        {
            if ((charMap_ascii[(unsigned char)ch][i] << j) & 0x80)
            {
                drawBox_(x + (j * f), y + (i * f), f, f, c, buffer);
            }
        }
    }
}
