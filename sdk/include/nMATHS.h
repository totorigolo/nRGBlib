#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#ifndef PI
#define PI 3.14159265
#endif

/// Choose an random number (based on the number of time the function is called)
int rand();
inline int randMinMax(int min, int max); // min & max included

#endif // MATHS_H_INCLUDED
