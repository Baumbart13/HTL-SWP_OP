//
// Created by Baumbart13 on 17.05.2021.
//

#ifndef HTL_SWP_OP_RANDOM_H
#define HTL_SWP_OP_RANDOM_H

#include "measureStuff.h"

myArray* createRandomArray(unsigned = OFFICIAL_TEST_ARRAY_LENGTH);
myArray* initTestArray();
void initRandomArray(myArray *destArr);
void initRandomArray(myArray *destArr, unsigned destArrLength);
void initSortedArray(myArray *destArr);
void initSortedArray(myArray *destArr, unsigned destArrLength);
int getRandomElement();
int getUniqueRandomElement();
void copyOfficialTestArray(myArray *destArr);
void copyOfficialTestArray(myArray *destArr, unsigned destArrLength);

#endif //HTL_SWP_OP_RANDOM_H
