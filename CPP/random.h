//
// Created by Baumbart13 on 17.05.2021.
//

#ifndef HTL_SWP_OP_RANDOM_H
#define HTL_SWP_OP_RANDOM_H

#include "measureStuff.h"

const unsigned OFFICIAL_TEST_ARRAY_LENGTH = 1000000u;

myArray* createRandomArray(unsigned = OFFICIAL_TEST_ARRAY_LENGTH);
myArray* initTestArray();
void initRandomArray(myArray *destArr, unsigned destArrLength);
int getRandomElement();
int getUniqueRandomElement();

myArray *OFFICIAL_TEST_ARRAY = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);

void copyOfficialTestArray(myArray *destArr, int destArrLength);

#endif //HTL_SWP_OP_RANDOM_H
