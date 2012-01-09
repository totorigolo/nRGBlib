#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#ifndef PI
#define PI 3.14159265
#endif

/// Calcule la factorielle
int Factorielle(int n);

/// Calcule la puissance
float Puissance(float x, int y);

/// Calcule le cosinus
float Cosinus(float x);

/// Calcule le sinus
float Sinus(float x);

/// Echange les valeurs de deux entiers
void echangerEntiers(short int* x, short int* y);

/// Calcule l'inverse de la valeur entre 0 et 1
float Inverse(float val);

/// Choisi un nombre aléatoire (basé sur le nombre de fois que la fonction est appelée)
int rand();
inline int randMinMax(int min, int max);

#endif // MATHS_H_INCLUDED
