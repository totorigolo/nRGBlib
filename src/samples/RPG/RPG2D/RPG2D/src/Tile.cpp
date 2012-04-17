#include "Tile.h"

// Ctors
Tile::Tile(void)
	: x(0),
	y(0),
	collision(0),
	nextTile(-1)
{
}
Tile::Tile(unsigned int _x, unsigned int _y, unsigned char _collision, int _nextTile)
	: x(_x),
	y(_y),
	collision(_collision),
	nextTile(_nextTile)
{
}
