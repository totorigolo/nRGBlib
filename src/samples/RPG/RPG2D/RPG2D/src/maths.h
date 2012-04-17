// Quelques fonctions mathématiques
#pragma once
#include <cmath>

namespace Maths
{
	// Un rand sans srand =D
	int rand_(void)
	{
		static int m_w = 56789;
		static int m_z = 38765;

		m_z = 36969 * (m_z & 65535) + (m_z >> 16);
		m_w = 18000 * (m_w & 65535) + (m_w >> 16);

		return (m_z << 16) + m_w;
	}
	// min and max included
	inline int randMinMax(int min, int max)
	{
		if ((max - min + 1) + min == 0) return 0;
		return abs(rand()) % (max - min + 1) + min;
	}
}