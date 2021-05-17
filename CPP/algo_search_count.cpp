//
// Created by Baumbart13 on 13.04.2021.
//

#include "algo.h"
//#ifndef ALGOS_MEASURESTUFF_H
//#include "measureStuff.h"
//#endif

namespace algo::search{

	namespace algo::recursive{
		/// A recursive binary search on a sorted container.
		/// @returns the index of the element. <code>-1</code> if it is not inside the container.
		signed int binary(myArray arr, int searchFor, unsigned int lEnd, unsigned int rEnd, counter *c){
			c->increaseComparisons();
			if(rEnd >= arr.length())
				return -1;

			c->increaseComparisons();
			if(lEnd <= rEnd){

				c->increaseComparisons();
				if(arr.get(lEnd) == searchFor)
					return lEnd;

				c->increaseComparisons();
				if(arr.get(rEnd) == searchFor)
					return rEnd;


				// adjust middle
				c->increaseWrites();
				int middle = lEnd + ((rEnd - lEnd) / 2);
				c->increaseComparisons();
				if(arr.get(middle) == searchFor)
					return middle;

				c->increaseComparisons();
				if(searchFor < arr.get(middle)) {
					c->increaseRecursiveDepth();
					return binary(arr, searchFor, lEnd, middle, c);
				}
				c->increaseComparisons();
				if(searchFor > arr.get(middle)) {
					c->increaseRecursiveDepth();
					return binary(arr, searchFor, middle, rEnd, c);
				}
			}

			// Not found
			return -1;
		}

	}
	/// A binary search on a sorted container.
	/// @returns the index of the element. <code>-1</code> if it is not inside the container.
	signed int binary(myArray arr, int searchFor, counter *c){

		c->increaseWrites(2);
		int	left = 0,
			right = arr.length()-1;

		c->increaseComparisons();
		while(left <= right){
			c->increaseComparisons();
			if(arr.get(left) == searchFor)
				return left;

			c->increaseComparisons();
			if(arr.get(right) == searchFor)
				return right;

			// adjust middle
			c->increaseWrites();
			int middle = left + ((right - left) / 2);
			c->increaseComparisons();
			if(arr.get(middle) == searchFor)
				return middle;

			c->increaseComparisons();
			c->increaseWrites();
			if(searchFor < arr.get(middle))
				right = middle - 1;
			else
				left = middle + 1;
			c->increaseComparisons();
		}

		// Not found
		return -1;
	}

	/// A linear search on a container. Also works, if container is not sorted.
	/// @returns the index of the element. <code>-1</code> if it is not inside the container.
	signed int linear(myArray arr, int searchFor, counter *c){
		c->increaseWrites();
		c->increaseComparisons();
		for(unsigned int i = 0; i < arr.length(); ++i){
			c->increaseWrites();

			c->increaseComparisons();
			if(arr.get(i) == searchFor)
				return i;

			c->increaseComparisons();
		}
		// Not found
		return -1;
	}
}
