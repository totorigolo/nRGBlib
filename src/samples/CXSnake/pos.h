#ifndef POS_H
#define POS_H

typedef struct Pos Pos;
struct Pos
{
    int x;
    int y;
    Pos *next;
};

Pos* Pos_add(Pos *P, int x, int y);
Pos* Pos_pop(Pos *P);
#endif
