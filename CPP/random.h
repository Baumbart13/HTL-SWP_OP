//
// Created by Baumbart13 on 17.05.2021.
//

#ifndef HTL_SWP_OP_RANDOM_H
#define HTL_SWP_OP_RANDOM_H

const unsigned OFFICIAL_TEST_ARRAY_LENGTH = 1000000u;

int* createRandomArray(unsigned = OFFICIAL_TEST_ARRAY_LENGTH);
int* initTestArray();
void initRandomArray(int* destArr, unsigned destArrLength);
int getRandomElement();
int getUniqueRandomElement();
void copyOfficialTestArray(int* destArr, int destArrLength);

const int *OFFICIAL_TEST_ARRAY = initTestArray();

#endif //HTL_SWP_OP_RANDOM_H
