//
// Created by Baumbart13 on 12.04.2021.
//

#include "algo.h"
//#ifndef ALGOS_MEASURESTUFF_H
#include "measureStuff.h"
//#endif

namespace algo::sort{
	namespace algo::stable{
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
			auto i = l;
			auto j = r - 1;
			auto pivot = r;

			while (i < j) {
				while (i < r && arr->get(i) < arr->get(pivot))
					++i;
				while (j > l && arr->get(j) >= arr->get(pivot))
					--j;
				if (i < j)
					arr->swap(i, j);
			}
			if (arr->get(i) > arr->get(pivot))
				arr->swap(i, r);
			return i;
		}

		void quick(myArray *arr, unsigned low, unsigned high) {
			if (high <= low || abs((signed) high - (signed) low) <= 1)
				return;

			auto pivot = quickPartition(arr, low, high);
			quick(arr, low, pivot - 1);
			quick(arr, pivot + 1, high);
		}
		void quick(myArray *arr){
			quick(arr, 0, arr->length());
		}

		void mergeTogether(myArray *arr, unsigned l, unsigned m, unsigned r){



			return;
		}
		void merge(myArray *arr, unsigned l, unsigned r){
			if(l >= r || r >= arr->length()){
				return;
			}

			auto pivot = (l + (r-l)) / 2;

			merge(arr, l, pivot);
			merge(arr, pivot+1, r);
			mergeTogether(arr, l, pivot, r);
		}
		void merge(myArray *arr){
			merge(arr, 0, arr->length()-1);
		}
	}
}
