//
// Created by Baumbart13 on 12.04.2021.
//

#include "algo.h"
#include <iostream>
//#ifndef ALGOS_MEASURESTUFF_H
#include "measureStuff.h"
//#endif

namespace algo::sort{
	namespace stable{
		void selection(myArray *arr){
			for(hugeValue i = 0; i < arr->length(); ++i){

				auto min = i;
				for(hugeValue j = i+1; j < arr->length(); ++j) {
					if(arr->get(min) > arr->get(j))
						min = j;
				}

				int key = arr->get(min);
				while(min > i){
					arr->set(min, arr->get(min-1));
					--min;
				}
				arr->set(i, key);
			}
			return;
		}

	}

	void selection(myArray *arr){
		for(hugeValue i = 0; i < arr->length(); ++i){

			auto min = i;
			for(hugeValue j = i+1; j < arr->length(); ++j){
				if(arr->get(min) > arr->get(j))
					min = j;
			}

			arr->swap(min, i);
		}
		return;
	}

	void bubble(myArray *arr){
		for(int i = 0; i < arr->length()-1; ++i){
			for(int j = 0; j < arr->length()-i-1; ++j){
				if(arr->get(j) > arr->get(j+1)){
					arr->swap(j, j+1);
				}
			}
		}
		return;
	}

	void insertion(myArray *arr){
		int	i,
			j,
			key;
		for(i = 1; i < arr->length(); ++i){
			key = arr->get(i);
			j = i-1;

			while(j >= 0 && arr->get(j) > key){
				arr->set(j+1, arr->get(j));
				--j;
			}
			arr->set(j+1, key);
		}
		return;
	}

	namespace recursive {
		unsigned quickPartition(myArray *arr, const unsigned l, const unsigned r) {
			auto lIndex = l;
			auto rIndex = r - 1;
			auto pivot = arr->get(r);

			while (lIndex < rIndex) {
				while (lIndex < r && arr->get(lIndex) < pivot)
					++lIndex;
				while (rIndex > l && arr->get(rIndex) >= pivot)
					--rIndex;
				if (lIndex < rIndex)
					arr->swap(lIndex, rIndex);
			}
			if (arr->get(lIndex) > pivot)
				arr->swap(lIndex, r);
			return lIndex;
		}

		void quick(myArray *arr, unsigned low, unsigned high) {
			if(low >= high){
				return;
			}

			auto pivot = quickPartition(arr, low, high);
			quick(arr, low, pivot - 1);
			quick(arr, pivot + 1, high);
		}
		void quick(myArray *arr){
			quick(arr, 0, arr->length()-1);
		}

		void mergeTogether(myArray *arr, unsigned l, unsigned r) {

			const auto middle = (l + (r - l)) / 2;

			// copy lower half to new temporary array
			auto lowerArrSize = middle - l + 1;
			auto lowerArr = new myArray(lowerArrSize);
			for (unsigned i = 0; i < lowerArrSize; ++i) {
				lowerArr->set(i, arr->get(l + i));
			}

			// copy upper half to new temporary array
			auto upperArrSize = r - middle;
			auto upperArr = new myArray(upperArrSize);
			for (unsigned i = 0; i < upperArrSize; ++i) {
				upperArr->set(i, arr->get(middle + i + 1));
			}

			// create indices for merging
			unsigned lowerArrIndex = 0, upperArrIndex = 0, resultsArrIndex = l;

			// merge all together
			//   lowerArrIndex can't be greater equals than underArrSize
			//   upperArrIndex can't be greater equals than upperArrSize
			//   resultsArrIndex can't be less than l
			//   resultsArrIndex can't be greater equals than r
			// if EITHER the upper array is done OR the lower array is done, then go for the next step where the
			// resuming parts of the counterpart is getting inserted
			while (lowerArrIndex < lowerArrSize && upperArrIndex < upperArrSize) {
				auto lowerElement = (lowerArr->get(lowerArrIndex)); // just for comparison!!!
				auto upperElement = (upperArr->get(upperArrIndex)); // just for comparison!!!

				if (lowerElement <= upperElement) {
					arr->set(resultsArrIndex++, lowerArr->get(lowerArrIndex++));
				} else {
					arr->set(resultsArrIndex++, upperArr->get(upperArrIndex++));
				}
			}

			// one temporary array was inserted completely, the other one has elements left in it
			// (even if it is only 1 element) just copy the resuming elements to the resulting

			// if lower array is done, then the upper can't be the same as the upperSize and therefore we
			// copy the resuming values from the upper one to the resulting
			// it won't execute the while, if the upper one is done and the lower is not
			while (upperArrIndex < upperArrSize) {
				arr->set(resultsArrIndex++, upperArr->get(upperArrIndex++));
			}

			// if upper array is done, then the lower can't be the same as the lowerSize and therefore we
			// copy the resuming values from the lower one to the resulting
			// it won't execute the while, if the lower one is done and the upper is not
			while (lowerArrIndex < lowerArrSize) {
				arr->set(resultsArrIndex++, lowerArr->get(lowerArrIndex++));
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

		void merge(myArray *arr, unsigned l, unsigned r) {
			if (l >= r || r >= arr->length()) {
				return;
			}

			// make the pivot element as the middle one
			auto pivot = (l + (r - l)) / 2;

			// first mergeSort the lower half
			merge(arr, l, pivot);
			// second, mergeSort the upper half
			merge(arr, pivot + 1, r);
			// and finally merge lower and upper half together
			mergeTogether(arr, l, r);
		}

		void merge(myArray *arr) {
			merge(arr, 0, arr->length() - 1);
		}
	}
}
