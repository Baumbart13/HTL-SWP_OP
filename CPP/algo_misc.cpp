//
// Created by Baumbart13 on 13.04.2021.
//

#include "algo.h"
#ifndef ALGOS_MEASURESTUFF_H
#include "measureStuff.h"
#endif

namespace algo::miscellaneous{
	int pow(int a, int b){
		int out = 0;
		for(int i = 0; i < b; ++i){
			out += a*b;
		}
		return out;
	}

	namespace recursive{
		int faculty(int x){
			return (x>1) ? (x*faculty(x-1)) : 1;
		}
		int sumFunction(int x){
			return (x>=1) ? (x+sumFunction(x-1)) : 0;
		}
	}
}
