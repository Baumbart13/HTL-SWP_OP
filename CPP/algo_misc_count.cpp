//
// Created by Baumbart13 on 06.06.2021.
//

#include "algo.h"
#ifndef ALGOS_MEASURESTUFF_H
#include "measureStuff.h"
#endif

namespace algo::miscellaneous{
	int pow(int a, int b, counter *c){
		c->increaseWrites(2);
		int out = 0;
		c->increaseComparisons();
		for(int i = 0; i < b; ++i){
			c->increaseWrites();
			out += a*b;
			c->increaseComparisons();
		}
		return out;
	}

	namespace recursive{
		int faculty(int x, counter *c){
			c->increaseComparisons();
			c->increaseRecursiveDepth();
			return (x>1) ? (x*faculty(x-1, c)) : 1;
		}
		int sumFunction(int x, counter *c){
			c->increaseComparisons();
			c->increaseRecursiveDepth();
			return (x>=1) ? (x+sumFunction(x-1, c)) : 0;
		}
	}
}
