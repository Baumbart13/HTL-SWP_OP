//
// Created by Baumbart13 on 12.04.2021.
//

#ifndef ALGOS_ALGO_H
#define ALGOS_ALGO_H

#include "measureStuff.h"


namespace algo::sort {
	namespace stable{
		void selection(myArray *arr);
		void selection(myArray *arr, counter *c);
	}
	void bubble(myArray *arr);
	void bubble(myArray *arr, counter *c);

	void insertion(myArray *arr);
	void insertion(myArray *arr, counter *c);

	void selection(myArray *arr);
	void selection(myArray *arr, counter *c);

	namespace recursive {
		void quick(myArray *arr);
		void quick(myArray *arr, counter *c);

		void merge(myArray *arr);
		void merge(myArray *arr, counter *c);
	}
}

namespace algo::search {
	signed int linear(myArray arr, int searchFor);
	signed int linear(myArray arr, int searchFor, counter *c);

	signed int doublyLinear(myArray arr, int searchFor);
	signed int doublyLinear(myArray arr, int searchFor, counter *c);

	signed int quadrupleLinear(myArray arr, int searchFor);
	signed int quadrupleLinear(myArray arr, int searchFor, counter *c);

	signed int binary(myArray &arr, int searchFor);
	signed int binary(myArray &arr, int searchFor, counter *c);

	namespace recursive {
		signed int binary(myArray arr, int searchFor, unsigned int lEnd, unsigned int rEnd);
		signed int binary(myArray arr, int searchFor, unsigned int lEnd, unsigned int rEnd, counter *c);
	}
}

namespace algo::miscellaneous{
	int pow(int x, int y);
	int pow(int x, int y, counter *c);

	namespace recursive{
		int faculty(int x);
		int faculty(int x, counter *c);

		int sumFunction(int x);
		int sumFunction(int x, counter *c);
	}
}


#endif //ALGOS_ALGO_H
