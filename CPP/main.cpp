#include <iostream>
#include <string>

#include "test_def.h"

bool wantsToExit = false;

void DemoLoop();
int main();


using std::string;

void DemoLoop(){
	using std::cout, std::endl;
	cout << "Hey there! Welcome to Baumbart13's program for testing some" <<
		 "algorithms. Searches, Sorting and miscellaneous stuff, e.g. factorial of a number." << endl;

	while(!wantsToExit){
		printWelcomeScreen();
	}

}

int main() {

	DemoLoop();

	std::cout << "Demo loop ended???" << std::endl;
	return 0;
}
