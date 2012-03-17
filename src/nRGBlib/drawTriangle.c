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

/// Draw an empty triangle to the given positions
void drawTriangle_(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3, Color c, ScreenBuffer buffer)
{
    drawLine_(x1, y1, x2, y2, c, buffer);
    drawLine_(x2, y2, x3, y3, c, buffer);
    drawLine_(x1, y1, x3, y3, c, buffer);
}
inline void drawTriangle(Triangle *t, Color c, ScreenBuffer buffer)
{
    drawTriangle_(t->x1, t->y1, t->x2, t->y2, t->x3, t->y3, c, buffer);
}
