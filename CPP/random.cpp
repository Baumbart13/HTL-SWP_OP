//
// Created by Baumbart13 on 17.05.2021.
//

#include "random.h"
#include <vector>

int getUniqueRandomElement(){
	static std::vector<int> usedValues = std::vector<int>(1);

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

int* initTestArray(){
	int arr[OFFICIAL_TEST_ARRAY_LENGTH];
	for(int i = 0; i < OFFICIAL_TEST_ARRAY_LENGTH; ++i){
		arr[i] = getUniqueRandomElement();
	}
	return arr;
}

void initRandomArray(int* destArr, unsigned destArrLength){
	for(int i = 0; i < destArrLength; ++i){
		destArr[i] = rand();
	}
}

void copyOfficialTestArray(int* destArr, int destArrLength){
	for(int i = 0; i < destArrLength; ++i){
		destArr[i] = OFFICIAL_TEST_ARRAY[i];
	}
}
