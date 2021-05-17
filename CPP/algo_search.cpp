//
// Created by Baumbart13 on 13.04.2021.
//

#include "algo.h"
#ifndef ALGOS_MEASURESTUFF_H
#include "measureStuff.h"
#endif

namespace algo::search{

	namespace algo::recursive{
		/// A recursive binary search on a sorted container.
		/// @returns the index of the element. <code>-1</code> if it is not inside the container.
		signed int binary(myArray arr, int searchFor, unsigned int lEnd, unsigned int rEnd){
			if(rEnd >= arr.length())
				return -1;

			if(lEnd <= rEnd){

				if(arr.get(lEnd) == searchFor)
					return lEnd;
				if(arr.get(rEnd) == searchFor)
					return rEnd;

				// adjust middle
				int middle = lEnd + ((rEnd - lEnd) / 2);
				if(arr.get(middle) == searchFor)
					return middle;

				if(searchFor < arr.get(middle))
					return binary(arr, searchFor, lEnd, middle);
				if(searchFor > arr.get(middle))
					return binary(arr, searchFor, middle, rEnd);
			}

			// Not found
			return -1;
		}

	}
	/// A binary search on a sorted container.
	/// @returns the index of the element. <code>-1</code> if it is not inside the container.
	signed int binary(myArray arr, int searchFor){
		int left = 0;
		int right = arr.length()-1;

		while(left <= right){
			if(arr.get(left) == searchFor)
				return left;

			if(arr.get(right) == searchFor)
				return right;

			// adjust middle
			int middle = left + ((right - left) / 2);
			if(arr.get(middle) == searchFor)
				return middle;

			if(searchFor < arr.get(middle))
				right = middle - 1;
			else
				left = middle + 1;
		}

		// Not found
		return -1;
	}

	/// A linear search on a container. Also works, if container is not sorted.
	/// @returns the index of the element. <code>-1</code> if it is not inside the container.
	signed int linear(myArray arr, int searchFor){
		for(unsigned int i = 0; i < arr.length(); ++i){
			if(arr.get(i) == searchFor)
				return i;
		}
		// Not found
		return -1;
	}
}
