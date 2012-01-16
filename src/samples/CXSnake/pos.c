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

#include "pos.h"
#include <os.h>

Pos* Pos_add(Pos *P, int x, int y)
{
    Pos *New = malloc(sizeof(Pos*));

    New->x = P->x + x;
    New->y = P->y + y;
    New->next = NULL;

    P->next = New;

    return New;
}
Pos* Pos_pop(Pos *P)
{
    if (P->next == NULL)
    {
        return P;
    }
    else
    {
        Pos *Next = P->next;
        free(P);
        return Next;
    }
}
