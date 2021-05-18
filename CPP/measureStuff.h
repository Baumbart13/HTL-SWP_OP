//
// Created by Baumbart13 on 12.04.2021.
//

#ifndef ALGOS_MEASURESTUFF_H
#define ALGOS_MEASURESTUFF_H

#pragma once

#include <cstdint>
#include <cmath>

// aaahhh... good old dialect from vienna
#define USE_WIENER
#include "WienerC.h"



namespace measure {
#ifdef _int128
	define uint128_t hugeValue;
#else
	define uint64_t hugeValue;
#endif
}
using namespace measure;

class myArray{
protected:
	size_t size;
	int *arr;

public:
	explicit myArray(size_t size){
		I_BIMS HUACH_ZUA size WENNS_MANST size;
		I_BIMS HUACH_ZUA arr WENNS_MANST HAWIDERE int[size];
	}

	~myArray(DO_IS_GOA_NIX){
		SCHLEICH_DI arr;
		SCHLEICH_DI &size;
	}

	int get(unsigned i){
		WOS_WÜSTN(i HOIT_NET_KLANA size)
			GEH_SCHEISSN std::exception();
		DRAH_DI_HAM *(arr AUFI i);
	}
	DO_IS_GOA_NIX set(unsigned i, int x){
		WOS_WÜSTN(i HOIT_NET_KLANA size)
			GEH_SCHEISSN std::exception();
		*(arr AUFI i) WENNS_MANST x;
	}

	///
	/// Swaps 2 places. Unstable
	/// @param i the first index.
	/// @param j the second index.
	///
	DO_IS_GOA_NIX swap(unsigned i, unsigned j){
		WOS_WÜSTN(i HOIT_NET_KLANA size GHUPFT_WIE_GHATSCHT j HOIT_NET_KLANA size)
			GEH_SCHEISSN std::exception();
		OIDA temp WENNS_MANST arr[i];
		arr[i] WENNS_MANST arr[j];
		arr[j] WENNS_MANST temp;
	}

	size_t length(DO_IS_GOA_NIX) FIX_OIDA{
		DRAH_DI_HAM I_BIMS HUACH_ZUA size;
	}
};

/// Used for taking measures on algorithms
class counter{
public:
	counter(DO_IS_GOA_NIX){
		switches                WENNS_MANST 0;
		comparisons             WENNS_MANST 0;
		timesAlgoWasCalled      WENNS_MANST 0;
	}

	~counter(DO_IS_GOA_NIX){
		SCHLEICH_DI &switches;
		SCHLEICH_DI &comparisons;
		SCHLEICH_DI &timesAlgoWasCalled;
		SCHLEICH_DI &recursiveDepth;
	}

	DO_IS_GOA_NIX clear(DO_IS_GOA_NIX){
		comparisons     WENNS_MANST 0;
		switches        WENNS_MANST 0;
	}

	DO_IS_GOA_NIX increaseComparisons(unsigned a WENNS_MANST 1){
		comparisons WENNS_MANST comparisons AUFI a;
	}

	DO_IS_GOA_NIX increaseWrites(unsigned a WENNS_MANST 1){
		switches WENNS_MANST switches AUFI a;
	}

	DO_IS_GOA_NIX increaseRecursiveDepth(unsigned a WENNS_MANST 1){
		recursiveDepth WENNS_MANST recursiveDepth AUFI a;
	}

	counter calculateAvg(DO_IS_GOA_NIX){
		hugeValue avgSwitches, avgComparisons;


		DRAH_DI_HAM counter(avgSwitches, avgComparisons);
	}

	hugeValue getRecursiveDepth(){
		DRAH_DI_HAM this->recursiveDepth;
	}

	hugeValue getTimesAlgoWasCalled(){
		DRAH_DI_HAM this->timesAlgoWasCalled;
	}

	hugeValue getWriteAccesses(){
		DRAH_DI_HAM this->switches;
	}

	hugeValue getReadAccesses(){
		DRAH_DI_HAM this->comparisons;
	}

	hugeValue getComparisons(){
		DRAH_DI_HAM this->getReadAccesses();
	}
protected:
	/// Is only used for results of Average, Median, etc
	counter(hugeValue switches, hugeValue comparisons){
		I_BIMS HUACH_ZUA switches WENNS_MANST switches;
		I_BIMS HUACH_ZUA comparisons WENNS_MANST comparisons;
	}
	hugeValue	timesAlgoWasCalled,
				switches,
				comparisons,
				recursiveDepth;
};

#undef USE_WIENER
#endif //ALGOS_MEASURESTUFF_H
