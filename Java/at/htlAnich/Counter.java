package at.htlAnich;

/**
 * Used for taking measures on algorithms.
 */
public class Counter {

	protected long	timesAlgoWasCalled=0,
					switches=0,
					comparisons=0,
					recursiveDepth=0,
					wrongSearches=0;

	/**
	 * Is only used for results of Average, Median, etc
	 */
	protected Counter(long switches, long comparisons){
		this.switches = switches;
		this.comparisons = comparisons;
	}


	public Counter(){
		this.clear();
	}

	void clear(){
		comparisons = 0;
		switches = 0;
		recursiveDepth = 0;
		timesAlgoWasCalled = 0;
		wrongSearches = 0;
	}

	void increaseWrongSearches(int x) {
		this.wrongSearches += x;
	}

	void increaseWrongSearches(){
		this.wrongSearches+=1;
	}

	void increaseComparisons(int x){
		this.comparisons += x;
	}

	void increaseComparisons(){
		this.comparisons+=1;
	}

	void increaseWrites(){
		this.switches+=1;
	}

	void increaseWrites(int x){
		this.switches += x;
	}

	void increaseRecursiveDepth(){
		this.recursiveDepth+=1;
	}

	void increaseRecursiveDepth(int x){
		this.recursiveDepth += x;
	}

	long getComparisons(){
		return this.comparisons;
	}

	long getWrites(){
		return this.switches;
	}

	long getRecursiveDepth(){
		return this.recursiveDepth;
	}

	long getWrongSearches(){
		return this.wrongSearches;
	}

	long getTimesAlgoWasCalled(){
		return this.timesAlgoWasCalled;
	}
}
