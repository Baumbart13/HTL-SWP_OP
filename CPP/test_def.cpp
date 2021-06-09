//
// Created by Baumbart13 on 27.04.2021.
//

#include "test_def.h"
#include "algo.h"
#include "random.h"
#include <iostream>
#include <string>

// YTAF does it say while linking, that the function is already defined??? 5 times??!?!?
// but not when it is inline?!?!?! WTF IS THIS C++?!?!
//
// hol' up.... pragma once not included?
#include <cstdint>
#include <chrono>

#warning "algo.h by Baumbart13 being preprocessed"

#ifdef _int128
#warning "can use 128bit wide primitive values"
#else
#warning "cannot use 128bit wide primitive values"
#endif

typedef std::chrono::steady_clock::time_point timePoint;

/** Returns the current time. */
timePoint timestamp(void) {
	return std::chrono::steady_clock::now();
	//return std::time(nullptr);
}

uint64_t calcTimeMicro(timePoint start, timePoint end){
	return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

uint64_t calcTimeNano(timePoint start, timePoint end){
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}


void bubble();
void insertion();
void selection();
void selectionStable();
void binary();
void binaryRecursive();
void faculty();
void facultyRecursive();
void sumfunction();
void sumfunctionRecursive();
void pow();
void powRecursive();
void quick();
void merge();

using   std::cout,
	std::end,
	std::endl,
	std::cin,
	std::string;

extern bool wantsToExit;

//////////////////////////////////////
//                                  //
//        HELPER FUNCTIONS          //
//                                  //
//////////////////////////////////////

void printResultsScreen(counter c, hugeValue time){
	cout << "Needed time: " << time << " microseconds."
		<< "\nComparisons: " << c.getComparisons()
		<< "\nWrites/Switches: " << c.getWriteAccesses()
		<< "\nRecursive Depth: " << c.getRecursiveDepth()
		<< "\nNumber of this algorithm was called: " << c.getTimesAlgoWasCalled() << endl;
}

void printResultsScreen_Misc(counter c){
	cout << "Comparisons: " << c.getComparisons()
		 << "\nWrites: " << c.getWriteAccesses()
		 << "\nRecursive Depth on 0xfe: " << c.getRecursiveDepth() << endl;
}

void toLower(string *s){
	std::transform(s->begin(), s->end(), s->begin(), [](unsigned char c){
               return std::tolower(c);
        });
}

//////////////////////////////////////
//                                  //
//     PRIMARY SELECTION SCREENS    //
//                                  //
//////////////////////////////////////

void printWelcomeScreen() {
	cout << "What do you want to test?" << endl <<
	     "[0] - Sorting algorithms" << endl <<
	     "[1] - Search algorithms" << endl <<
	     "[2] - Miscellaneous algorithms" << endl <<
	     "[x] - Exits program" << endl;
	char c;
	cin >> c;
	cin.clear();

	// gosh... switch statements are so damn easier for this
	// glad to have them
	switch(c){
		case '0':
			printSelectionScreen_Sort();
			break;
		case '1':
			printSelectionScreen_Search();
			break;
		case '2':
			printSelectionScreen_Other();
			break;
		case 'x':
			wantsToExit = true;
		default:
			return;
	}
}
void printSelectionScreen_Search(){
	cout << "Which sorting algorithm dou you want to see?" << endl <<
	     "[0] - Linear search" << endl <<
	     "[1] - Binary search" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);

	using namespace algo::search;

	if(c.compare("0")==0) {
		//linear();
	}else if(c.compare("1")==0){
		printSelectionScreen_BinarySearch();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}
void printSelectionScreen_Sort(){
	cout << "What do you want to test?" << endl <<
	     "[0] - Bubble sort" << endl <<
	     "[1] - Insertion sort" << endl <<
	     "[2] - Selection sort" << endl <<
	     "[3] - Quick sort" << endl <<
	     "[4] - Merge sort" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0) {
		bubble();
	}else if(c.compare("1")==0) {
		insertion();
	}else if(c.compare("2")==0) {
		printSelectionScreen_SelectionSort();
	}else if(c.compare("3")==0) {
		quick();
	}else if(c.compare("4")==0) {
		merge();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
	return;
}
void printSelectionScreen_Other(){
	cout << "What do you want to test?" << endl <<
	     "[0] - Faculty endrecursive" << endl <<
	     "[1] - Sumfunction endrecursive" << endl <<
	     "[2] - Power of a number" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		facultyRecursive();
	}else if(c.compare("1")==0){
		sumfunctionRecursive();
	}else if(c.compare("2")==0){
		pow();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}

//////////////////////////////////////
//                                  //
//     SEARCH SELECTION SCREEN      //
//                                  //
//////////////////////////////////////

void printSelectionScreen_BinarySearch(){

	cout << "What do you want to test?" << endl <<
	     "[0] - Normal" << endl <<
	     "[1] - Recursive" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		binary();
	}else if(c.compare("1")==0){
		binaryRecursive();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}

//////////////////////////////////////
//                                  //
//     SORT SELECTION SCREEN        //
//                                  //
//////////////////////////////////////

void printSelectionScreen_SelectionSort(){

	cout << "What do you want to test?" << endl <<
	     "[0] - Normal" << endl <<
	     "[1] - Stable" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		selection();
	}else if(c.compare("1")==0){
		selectionStable();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}

//////////////////////////////////////
//                                  //
//     MISC SELECTION SCREEN        //
//                                  //
//////////////////////////////////////


//////////////////////////////////////
//                                  //
//       EXECUTION OF ALGOS         //
//                                  //
//////////////////////////////////////

/*void bubble();
void insertion();
void selection();
void selectionStable();
void binary();
void binaryRecursive();
void faculty();
void facultyRecursive();
void sumfunction();
void sumfunctionRecursive();
void pow();
void powRecursive();*/
using std::cerr;

const int TIMES_TESTING = OFFICIAL_TEST_ARRAY_LENGTH/0xfe;

void notImplementedErrorMsg(string s){
	cerr << s << " not implemented yet" << endl;
}

//////////////////////////////////////
//                                  //
//               SORT               //
//                                  //
//////////////////////////////////////

void bubble(){

	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto arr = new myArray(10000);
		initRandomArray(arr);

		const auto start = timestamp();
		algo::sort::bubble(arr);
		const auto end = timestamp();

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initRandomArray(arr);
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr);
	auto count = new counter();
	algo::sort::bubble(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}
void insertion(){

	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto arr = new myArray(10000);
		initRandomArray(arr);

		const auto start = timestamp();
		algo::sort::insertion(arr);
		const auto end = timestamp();

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initRandomArray(arr);
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr, arr->length());
	auto count = new counter();
	algo::sort::insertion(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}
void selection(){

	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto arr = new myArray(10000);
		initRandomArray(arr);

		const auto start = timestamp();
		algo::sort::selection(arr);
		const auto end = timestamp();

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initRandomArray(arr);
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr, arr->length());
	auto count = new counter();
	algo::sort::selection(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}
void selectionStable(){

	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto arr = new myArray(10000);
		initRandomArray(arr);

		const auto start = timestamp();
		algo::sort::stable::selection(arr);
		const auto end = timestamp();

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initRandomArray(arr);
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr, arr->length());
	auto count = new counter();
	algo::sort::stable::selection(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}
void quick(){
	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto arr = new myArray(10);
		initRandomArray(arr);

		const auto start = timestamp();
		algo::sort::recursive::quick(arr);
		const auto end = timestamp();

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initRandomArray(arr);
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr, arr->length());
	auto count = new counter();
	algo::sort::recursive::quick(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}
void merge(){
	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto arr = new myArray(10000);
		initRandomArray(arr);

		const auto start = timestamp();
		algo::sort::recursive::merge(arr);
		const auto end = timestamp();

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initRandomArray(arr);
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr, arr->length());
	auto count = new counter();
	algo::sort::recursive::merge(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}

//////////////////////////////////////
//                                  //
//              SEARCH              //
//                                  //
//////////////////////////////////////

/**
 * May insert a random element into the container, modifies the element to the random one and returns whether it was
 * inserted or not.
 * @param destArr The container, where the element could be added to.
 * @param searchFor The element, that will be searched for and may gets inserted into the container.
 * @return if the element was inserted for check.
 */
bool insertElementToBeFound(myArray *destArr, int &searchFor){
	auto element = rand() % destArr->get(rand() % destArr->length());
	if(rand() % 101 >= 90){
		destArr->set(rand() % destArr->length(), element);
		return true;
	}
	return false;
}

void binary(){

	uint64_t wholeTime = 0;
	cout << "Measuring time..." << endl;
	for(int i = 0; i < TIMES_TESTING; ++i) {
		auto searchFor = nullptr;
		auto arr = new myArray(10000);
		initSortedArray(arr, arr->length());


		const auto start = timestamp();
		//auto ownIndex = algo::search::binary(arr, searchFor);
		const auto end = timestamp();

		//auto correctIndex = arr->

		cout << "step " << i+1 << " of " << TIMES_TESTING << " done" << endl;

		wholeTime = (wholeTime + calcTimeMicro(start, end)) / 2;

		initSortedArray(arr, arr->length());
	}

	cout << "Time measured, measuring steps..." << endl;

	auto arr = new myArray(OFFICIAL_TEST_ARRAY_LENGTH);
	copyOfficialTestArray(arr, arr->length());
	arr->sort();
	auto count = new counter();
	algo::sort::stable::selection(arr, count);


	printResultsScreen(*count, wholeTime);
	count->clear();
	delete count;
	delete arr;
}
void binaryRecursive(){notImplementedErrorMsg("BinaryRecursive");}

//////////////////////////////////////
//                                  //
//          MISCELLANEOUS           //
//                                  //
//////////////////////////////////////

void facultyRecursive(){
	int arr[TIMES_TESTING];
	for(int i = 0; i < TIMES_TESTING; ++i) {
		arr[i] = algo::miscellaneous::recursive::faculty(i);
	}
	auto c = new counter();
	algo::miscellaneous::recursive::faculty(0xfe, c);
	printResultsScreen_Misc(*c);
}
void sumfunctionRecursive(){
	int arr[TIMES_TESTING];
	for(int i = 0; i < TIMES_TESTING; ++i) {
		arr[i] = algo::miscellaneous::recursive::sumFunction(i);
	}
	auto c = new counter();
	algo::miscellaneous::recursive::sumFunction(0xfe, c);
	printResultsScreen_Misc(*c);
}
void pow(){
	int arr[TIMES_TESTING];
	for(int i = 0; i < TIMES_TESTING; ++i) {
		arr[i] = algo::miscellaneous::pow(0xfe, i);
	}
	auto c = new counter();
	algo::miscellaneous::pow(0xfe, 0xfe, c);
	printResultsScreen_Misc(*c);
}
