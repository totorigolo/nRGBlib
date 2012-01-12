#include <nMATHS.h>

/// Calcule la factorielle
int Factorielle(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

/// Calcule la puissance
float Puissance(float x, int y)
{
    int i;
    float puissance = 1;

    for (i = 1; i <= y;)
        puissance *= x;

    return puissance;
}

/// Calcule l'inverse de la valeur entre 0 et 1
inline float Inverse(float val)
{
    return (1 / val > 1) ? 1 : ((1 / val < 0) ? 0 : 1 / val);
}

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
