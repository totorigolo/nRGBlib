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

#include <nGEO.h>
#include <os.h>

/// Draw a box / rectangle in color
inline void drawBox_(int16_t x, int16_t y, int16_t w, int16_t h, Color c, ScreenBuffer buffer[76800])
{
    int32_t i, j;
    for (i = x; i < (x + w); i++)
        for (j = y; j < (y + h); j++)
            setPixel(i, j, c, buffer); // setPixel check if i and j are >0 and >320/240
}
inline void drawBox(Box *box, Color c, ScreenBuffer buffer[76800])
{
    drawBox_(box->x, box->y, box->w, box->h, c, buffer);
}

/// Draw a square in color
inline void drawSquare_(int16_t x, int16_t y, int16_t side, Color c, ScreenBuffer buffer[76800])
{
    drawBox_(x, y, side, side, c, buffer);
}
inline void drawSquare(Square *s, Color c, ScreenBuffer buffer[76800])
{
    drawBox_(s->x, s->y, s->side, s->side, c, buffer);
}
