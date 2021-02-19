#ifndef CRACKLIB_H
#define CRACKLIB_H

const float FREQ_TABLE[26] = {8.04, 1.48, 3.34, 3.82, 12.49, 2.40, 1.87, 5.05, 7.57, 0.16, 0.54, 4.07, 2.51,
                          7.23, 7.64, 2.14, 0.12, 6.28, 6.51, 9.28, 2.73, 1.05, 1.68, 0.23, 1.66, 0.09};

int
findMin(float* array, int len);

float*
characterFrequency(char* string);

float
chiSqr(float* es, float* os);

#endif
