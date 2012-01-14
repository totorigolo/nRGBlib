#include <nMATHS.h>

/// Choisi un nombre aléatoire (basé sur le nombre de fois que la fonction est appelée)
int rand()
{
    static int m_w = 56789;
    static int m_z = 38765;

    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);

    return (m_z << 16) + m_w;

    /*static unsigned int a = 1664525, b = 1013904223, m = 0x7FFFFFFF;
	static unsigned int nombre = 63642362;

    nombre = (a*nombre+ b) % m;

    return nombre;*/
}
/// \min inclu et \max inclu
inline int randMinMax(int min, int max)
{
    return abs(rand()) % (max - min + 1) + min;
}
