#include "pos.h"
#include "utils.h"
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
