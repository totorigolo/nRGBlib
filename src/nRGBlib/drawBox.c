/****************************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The Original Code is nRGBlib code.
 *
 * The Initial Developer of the Original Code is Thomas LACROIX aka totorigolo
 * <toto.rigolo@free.fr>.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 ****************************************************************************/

#include <nGEO.h>
#include <os.h>

/// Draw a box / rectangle in color
void drawBox_(int16_t x, int16_t y, int16_t w, int16_t h, Color c)
{
    int32_t i, j;
    for (i = x; i < (x + w) && i < 320; i++)
    {
        if (i < 0) continue;
        for (j = y; j < (y + h) && j < 240; j++)
        {
            if (j < 0) continue;
            setPixel(i, j, c);
        }
    }
}
inline void drawBox(Box *box, Color c)
{
    drawBox_(box->x, box->y, box->w, box->h, c);
}

/// Draw a square in color
inline void drawSquare_(int16_t x, int16_t y, int16_t side, Color c)
{
    drawBox_(x, y, side, side, c);
}
inline void drawSquare(Square *s, Color c)
{
    drawBox_(s->x, s->y, s->side, s->side, c);
}
