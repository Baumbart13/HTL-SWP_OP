//
// Created by Baumbart13 on 13.04.2021.
//
//#ifndef ALGOS_MEASURESTUFF_H
//#include "measureStuff.h"
//#endif
#include "algo.h"

namespace algo::sort{
	namespace algo::stable{

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
	}
}
