//
// Created by Baumbart13 on 13.04.2021.
//
//#ifndef ALGOS_MEASURESTUFF_H
//#include "measureStuff.h"
//#endif
#include "algo.h"

namespace algo::sort{
	namespace stable{

		///////////////
		void selection(myArray *arr, counter *c){
			c->increaseWrites();
			c->increaseComparisons();
			for(hugeValue i = 0; i < arr->length(); ++i){
				c->increaseWrites(2);
				auto min = i;

				c->increaseWrites();
				c->increaseComparisons();
				for(hugeValue j = i+1; j < arr->length(); ++j) {
					c->increaseWrites();

					c->increaseComparisons();
					if(arr->get(min) > arr->get(j)) {
						c->increaseWrites();
						min = j;
					}
				}

				c->increaseWrites();
				int key = arr->get(min);

				c->increaseComparisons();
				while(min > i){

					c->increaseWrites(2);
					arr->set(min, arr->get(min-1));
					--min;

					c->increaseComparisons();
				}
				c->increaseWrites();
				arr->set(i, key);
			}
			return;
		}

	}

	void selection(myArray *arr, counter *c){
		c->increaseWrites();
		c->increaseComparisons();
		for(hugeValue i = 0; i < arr->length(); ++i){
			c->increaseWrites(2);
			auto min = i;

			c->increaseWrites();
			c->increaseComparisons();
			for(hugeValue j = i+1; j < arr->length(); ++j){
				c->increaseWrites();

				c->increaseComparisons();
				if(arr->get(min) > arr->get(j)) {
					c->increaseWrites();
					min = j;
				}
			}

			c->increaseWrites(3);
			arr->swap(min, i);
		}
		return;
	}

	void bubble(myArray *arr, counter *c){
		c->increaseWrites();
		c->increaseComparisons();
		for(int i = 0; i < arr->length()-1; ++i){
			c->increaseWrites();

			c->increaseWrites();
			c->increaseComparisons();
			for(int j = 0; j < arr->length()-i-1; ++j){
				c->increaseWrites();

				c->increaseComparisons();
				if(arr->get(j) > arr->get(j+1)){
					c->increaseWrites(3);
					arr->swap(j, j+1);
				}
			}
		}
		return;
	}



	void insertion(myArray *arr, counter *c){
		int	i,
			j,
			key;

		c->increaseWrites();
		c->increaseComparisons();
		for(i = 1; i < arr->length(); ++i){
			key = arr->get(i);
			j = i-1;
			c->increaseWrites(3);

			c->increaseComparisons(2);
			while(j >= 0 && arr->get(j) > key){

				c->increaseWrites(2);
				arr->set(j+1, arr->get(j));
				--j;

				c->increaseComparisons(2);
			}
			c->increaseWrites();
			arr->set(j+1, key);
		}
		return;
	}


	namespace recursive {
		unsigned quickPartition(myArray *arr, const unsigned l, const unsigned r, counter *c) {
			auto i = l;
			auto j = r - 1;
			auto pivot = r;
			c->increaseWrites(3);

			c->increaseComparisons();
			while (i < j) {
				c->increaseComparisons(2);
				while (i < r && arr->get(i) < arr->get(pivot)) {
					++i;
					c->increaseWrites();
				}
				c->increaseComparisons(2);
				while (j > l && arr->get(j) >= arr->get(pivot)) {
					--j;
					c->increaseWrites();
				}
				c->increaseComparisons();
				if (i < j) {
					c->increaseWrites(3);
					arr->swap(i, j);
				}
			}
			c->increaseComparisons(2);
			if (arr->get(i) > arr->get(pivot)) {
				c->increaseWrites(3);
				arr->swap(i, r);
			}
			return i;
		}

		void quick(myArray *arr, unsigned low, unsigned high, counter *c) {
			c->increaseComparisons(2);
			if (high <= low || abs((signed) high - (signed) low) <= 1)
				return;

			auto pivot = quickPartition(arr, low, high, c);
			c->increaseRecursiveDepth();
			quick(arr, low, pivot - 1, c);
			c->increaseRecursiveDepth();
			quick(arr, pivot + 1, high, c);
		}
		void quick(myArray *arr, counter *c){
			quick(arr, 0, arr->length(), c);
		}


		void mergeTogether(myArray *arr, unsigned l, unsigned r, counter *c) {

			c->increaseWrites();
			const auto middle = (l + (r - l)) / 2;

			// copy lower half to new temporary array
			c->increaseWrites(2); // assuming that a new "myArray" is only a pointer and therefore only 1 writeAccess
			auto lowerArrSize = middle - l + 1;
			auto lowerArr = new myArray(lowerArrSize);
			for (unsigned i = 0; i < lowerArrSize; ++i) {
				c->increaseWrites();
				lowerArr->set(i, arr->get(l + i));
			}

			// copy upper half to new temporary array
			c->increaseWrites(2); // assuming that a new "myArray" is only a pointer and therefore only 1 writeAccess
			auto upperArrSize = r - middle;
			auto upperArr = new myArray(upperArrSize);
			for (unsigned i = 0; i < upperArrSize; ++i) {
				c->increaseWrites();
				upperArr->set(i, arr->get(middle + i + 1));
			}

			// create indices for merging
			c->increaseWrites(3);
			unsigned lowerArrIndex = 0, upperArrIndex = 0, resultsArrIndex = l;

			// merge all together
			//   lowerArrIndex can't be greater equals than underArrSize
			//   upperArrIndex can't be greater equals than upperArrSize
			//   resultsArrIndex can't be less than l
			//   resultsArrIndex can't be greater equals than r
			// if EITHER the upper array is done OR the lower array is done, then go for the next step where the
			// resuming parts of the counterpart is getting inserted
			c->increaseComparisons(2);
			while (lowerArrIndex < lowerArrSize && upperArrIndex < upperArrSize) {
				c->increaseWrites(2);
				auto lowerElement = (lowerArr->get(lowerArrIndex)); // just for comparison!!!
				auto upperElement = (upperArr->get(upperArrIndex)); // just for comparison!!!

				c->increaseComparisons();
				c->increaseWrites(3);
				if (lowerElement <= upperElement) {
					arr->set(resultsArrIndex++, lowerArr->get(lowerArrIndex++));
				} else {
					arr->set(resultsArrIndex++, upperArr->get(upperArrIndex++));
				}
				c->increaseComparisons(2);
			}

			// one temporary array was inserted completely, the other one has elements left in it
			// (even if it is only 1 element) just copy the resuming elements to the resulting

			// if lower array is done, then the upper can't be the same as the upperSize and therefore we
			// copy the resuming values from the upper one to the resulting
			// it won't execute the while, if the upper one is done and the lower is not
			c->increaseComparisons();
			while (upperArrIndex < upperArrSize) {
				c->increaseWrites(3);
				arr->set(resultsArrIndex++, upperArr->get(upperArrIndex++));
				c->increaseComparisons();
			}

			// if upper array is done, then the lower can't be the same as the lowerSize and therefore we
			// copy the resuming values from the lower one to the resulting
			// it won't execute the while, if the lower one is done and the upper is not
			c->increaseComparisons();
			while (lowerArrIndex < lowerArrSize) {
				c->increaseWrites(3);
				arr->set(resultsArrIndex++, lowerArr->get(lowerArrIndex++));
				c->increaseComparisons();
			}

			// everything is merged together as it should be
			// so let's clean up all the mess we made up before and then return out of here
			delete lowerArr;
			delete upperArr;
			// unfortunately we cannot delete the extra variables, because they are not pointers (yet, hehe)
			//delete middle;
			//delete lowerArrSize;
			//delete lowerArrIndex;
			//delete upperArrSize;
			//delete upperArrIndex;
			//delete resultsArrIndex;

			return;
		}

		void merge(myArray *arr, unsigned l, unsigned r, counter *c) {
			c->increaseComparisons(2);
			if (l >= r || r >= arr->length()) {
				return;
			}

			// make the pivot element as the middle one
			c->increaseWrites();
			auto pivot = (l + (r - l)) / 2;

			// first mergeSort the lower half
			c->increaseRecursiveDepth();
			merge(arr, l, pivot, c);
			// second, mergeSort the upper half
			c->increaseRecursiveDepth();
			merge(arr, pivot + 1, r, c);
			// and finally merge lower and upper half together
			mergeTogether(arr, l, r, c);
		}

		void merge(myArray *arr, counter *c) {
			merge(arr, 0, arr->length() - 1, c);
		}
	}
}
