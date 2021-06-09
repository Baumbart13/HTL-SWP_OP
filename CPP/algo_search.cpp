//
// Created by Baumbart13 on 13.04.2021.
//

#include "algo.h"
#ifndef ALGOS_MEASURESTUFF_H
#include "measureStuff.h"
#endif

namespace algo::search{

	namespace recursive{
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
	signed int binary(myArray &arr, int searchFor){
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

	signed int doublyLinear(myArray arr, int searchFor){

		// simple double sided sequentialSearch, just to make sure there is definitely the value inside
		int lowerIndex = 0;
		int upperIndex = arr.length()-1;

		while(lowerIndex <= upperIndex){
			if(arr.get(lowerIndex) == searchFor){
				return lowerIndex;
			}
			if(arr.get(upperIndex) == searchFor){
				return upperIndex;
			}
			++lowerIndex;
			--upperIndex;
		}
		return -1;
	}

	signed int quadrupleLinear(myArray arr, int searchFor){
		// one index starts from the lower end
		int llIndex = 0;
		// one index starts from the upper end
		int rrIndex = arr.length()-1;
		// one index starts from the middle and goes downwards
		int mlIndex = arr.length()/2;
		// one index starts from the middle and goes upwards
		int mrIndex = arr.length()/2;

		while(llIndex <= mlIndex &&
		rrIndex >= mrIndex){
			if(arr.get(llIndex) == searchFor){
				return llIndex;
			}
			if(arr.get(rrIndex) == searchFor){
				return rrIndex;
			}
			if(arr.get(mlIndex) == searchFor){
				return mlIndex;
			}
			if(arr.get(mrIndex) == searchFor){
				return mrIndex;
			}

			++llIndex;
			--rrIndex;
			--mlIndex;
			++mrIndex;
		}

		return -1;
	}
}
