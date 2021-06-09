#include <iostream>
#include <string>

#include "test_def.h"
#include "measureStuff.h"
#include "algo.h"

//#define FUCK

bool wantsToExit = false;

void DemoLoop();
int main();


using std::string;

void DemoLoop(){
	using std::cout, std::endl;
	cout << "Hey there! Welcome to Baumbart13's program for testing some" <<
		 "algorithms. Searches, Sorting and miscellaneous stuff, e.g. factorial of a number." << endl;

#ifdef FUCK
	cout << "Quick sort with 10 elements: " <<endl;
	auto arr = new myArray(10);arr->set(0, 5);
	arr->set(1, 3);
	arr->set(2, 6);
	arr->set(3, 4);
	arr->set(4, 8);
	arr->set(5, 0);
	arr->set(6, 1);
	arr->set(7, 2);
	arr->set(8, 7);
	arr->set(9, 9);
	for(int i = 0; i < 10; ++i){
		printf("Index: %d; value: %d\n", i, arr->get(i));
	}
	algo::sort::recursive::quick(arr);
	for(int i = 0; i < 10; ++i){
		printf("Index: %d; value: %d\n", i, arr->get(i));
	}
	wantsToExit = true;
#endif // FUCK

	while(!wantsToExit){
		printWelcomeScreen();
	}

}

int main() {

	DemoLoop();

	std::cout << "Demo loop ended???" << std::endl;
	return 0;
}
