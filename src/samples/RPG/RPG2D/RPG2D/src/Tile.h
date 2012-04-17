#pragma once

struct Tile
{
	Tile(void);
	Tile(unsigned int _x, unsigned int _y, unsigned char _collision, int _nextTile);

	/* Coordonnée du tile dans le chipset */
	unsigned int x;
	unsigned int y;

	/* Indique si l'on peut traverser ou pas le tile */
	unsigned char collision;

	/* Indique le numéro du prochain tile dans l'animation
	ou -1 si le tile n'est pas animé. */
	int nextTile;
};