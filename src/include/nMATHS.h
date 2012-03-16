#ifndef NMATHS_H_INCLUDED
#define NMATHS_H_INCLUDED

#ifndef PI
#define PI 3.14159265
#endif

/// Choose a random number (based on the number of time the function is called)
int rand();
inline int randMinMax(int min, int max); // min and max included

#endif // NMATHS_H_INCLUDED
