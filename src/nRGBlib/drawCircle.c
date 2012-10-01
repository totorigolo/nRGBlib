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

/// Draw a circle in color
void drawCircle_(int16_t x, int16_t y, int16_t radius, Color c, ScreenBuffer buffer)
{
    int16_t x2 = 0;
    int16_t y2 = radius; // On se place en haut du cercle
    int32_t m = 5 - 4 * radius; // Initialisation

    while (x2 <= y2) // Tant qu'on est dans le second octant
    {
        setPixel( x2 + x,  y2 + y, c, buffer);
        setPixel( y2 + x,  x2 + y, c, buffer);
        setPixel(-x2 + x,  y2 + y, c, buffer);
        setPixel(-y2 + x,  x2 + y, c, buffer);
        setPixel( x2 + x, -y2 + y, c, buffer);
        setPixel( y2 + x, -x2 + y, c, buffer);
        setPixel(-x2 + x, -y2 + y, c, buffer);
        setPixel(-y2 + x, -x2 + y, c, buffer);

        if (m > 0) // Choix du point
        {
            y2--;
            m -= 8 * y2;
        }
        x2++;
        m += 8 * x2 + 4;
    }
}
void drawCircle(Circle *c, Color col, ScreenBuffer buffer)
{
    drawCircle_(c->x, c->y, c->radius, col, buffer);
}
