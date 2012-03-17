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

/// Draw a disc in color
void drawDisc_(int16_t x, int16_t y, int16_t radius, Color c, ScreenBuffer buffer)
{
    int16_t x2 = 0;
    int16_t y2 = radius;
    int32_t d = 3 - (2 * radius);
    int32_t i, j;

    while (y2 >= x2)
    {
        drawBox_(x - x2, y - y2, 2 * x2 + 1, 1, c, buffer);
        drawBox_(x - x2, y + y2, 2 * x2 + 1, 1, c, buffer);
        drawBox_(x - y2, y - x2, 2 * y2 + 1, 1, c, buffer);
        drawBox_(x - y2, y + x2, 2 * y2 + 1, 1, c, buffer);

        if (d < 0)
            d += (4 * x2) + 6;
        else
        {
            d += 4 * (x2 - y2) + 10;
            y2--;
        }
        x2++;
    }
}
inline void drawDisc(Disc *d, Color c, ScreenBuffer buffer)
{
    drawDisc_(d->x, d->y, d->radius, c, buffer);
}
