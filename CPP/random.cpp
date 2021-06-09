//
// Created by Baumbart13 on 17.05.2021.
//

#include "random.h"
#include <vector>

int getUniqueRandomElement(){
	static auto usedValues = std::vector<int>(1);

	int randomElement = 0;
	do{
		randomElement = rand();
	}while(*find(usedValues.begin(), usedValues.end(), randomElement) == randomElement);

	usedValues.push_back(randomElement);
	return randomElement;
}

int getRandomElement(){
	return rand();
}

myArray* initTestArray(){
	myArray *arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	for(int i = 0; i < OFFICIAL_TEST_ARRAY_LENGTH; ++i){
		arr->set(i, getUniqueRandomElement());
	}
	return arr;
}

void initSortedArray(myArray *destArr){ initSortedArray(destArr, destArr->length()); }
void initSortedArray(myArray *destArr, unsigned destArrLength){
	for(int i = 0; i < destArrLength; ++i){
		destArr->set(i, rand() % (i<<1));
	}
	destArr->sort();
}

void initRandomArray(myArray *destArr){ initRandomArray(destArr, destArr->length()); }
void initRandomArray(myArray *destArr, unsigned destArrLength){
	for(int i = 0; i < destArrLength; ++i){
		destArr->set(i, rand());
	}
}

void copyOfficialTestArray(myArray *destArr){ copyOfficialTestArray(destArr, destArr->length()); }

void copyOfficialTestArray(myArray *destArr, unsigned destArrLength){
	for(int i = 0; i < destArrLength; ++i){
		destArr->set(i, OFFICIAL_TEST_ARRAY->get(i));
	}
}
