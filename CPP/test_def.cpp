//
// Created by Baumbart13 on 27.04.2021.
//

#include "test_def.h"
#include "algo.h"
#include <iostream>
#include <string>

// YTAF does it say while linking, that the function is already defined??? 5 times??!?!?
// but not when it is inline?!?!?! WTF IS THIS C++?!?!
//
// hol' up.... pragma once not included?
#include <cstdint>
#include <chrono>

#warning "algo.h by Baumbart13 being preprocessed"
/// Returns the amount of seconds passed since <code>01-Jan-1970</code>.
#ifdef _int128
uint128_t
#else
uint64_t
#endif
timestamp(void) {
	return std::time(nullptr);
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
		merge();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}
void printSelectionScreen_Other(){
	cout << "What do you want to test?" << endl <<
	     "[0] - Faculty" << endl <<
	     "[1] - Sumfunction" << endl <<
	     "[2] - Power of a number recursive" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		printSelectionScreen_FacultyMisc();
	}else if(c.compare("1")==0){
		printSelectionScreen_SumfunctionMisc();
	}else if(c.compare("2")==0){
		printSelectionScreen_PowMisc();
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

void printSelectionScreen_FacultyMisc(){

	cout << "What do you want to test?" << endl <<
	     "[0] - Normal" << endl <<
	     "[1] - Recursive" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		faculty();
	}else if(c.compare("1")==0){
		facultyRecursive();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}
void printSelectionScreen_SumfunctionMisc(){

	cout << "What do you want to test?" << endl <<
	     "[0] - Normal" << endl <<
	     "[1] - Recursive" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		sumfunction();
	}else if(c.compare("1")==0){
		sumfunctionRecursive();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}
void printSelectionScreen_PowMisc(){

	cout << "What do you want to test?" << endl <<
	     "[0] - Normal" << endl <<
	     "[1] - Recursive" << endl <<
	     "[x] - Exits program" << endl;

	string c;
	cin >> c;
	cin.clear();
	toLower(&c);


	if(c.compare("0")==0){
		pow();
	}else if(c.compare("1")==0){
		powRecursive();
	}else if(c.compare("x")==0){
		wantsToExit = true;
	}else{
		return;
	}
}

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

void notImplementedErrorMsg(string s){
	cerr << s << " not implemented yet" << endl;
}

void bubble(){ notImplementedErrorMsg("Bubble");}
void insertion(){notImplementedErrorMsg("Insertion");}
void selection(){notImplementedErrorMsg("Selection");}
void selectionStable(){notImplementedErrorMsg("SelectionStable");}
void merge(){ notImplementedErrorMsg("Merge");}

void binary(){notImplementedErrorMsg("Binary");}
void binaryRecursive(){notImplementedErrorMsg("BinaryRecursive");}
void faculty(){notImplementedErrorMsg("Faculty");}
void facultyRecursive(){notImplementedErrorMsg("FacultyRecursive");}
void sumfunction(){notImplementedErrorMsg("SumFunction");}
void sumfunctionRecursive(){notImplementedErrorMsg("SumFunctionRecursive");}
void pow(){notImplementedErrorMsg("Power");}
void powRecursive(){notImplementedErrorMsg("PowerRecursive");}
