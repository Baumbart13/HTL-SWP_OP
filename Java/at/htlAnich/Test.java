package at.htlAnich;

import java.util.Locale;
import java.util.Scanner;

import static at.htlAnich.Random.OFFICIAL_TEST_ARRAY_LENGTH;
import static at.htlAnich.tools.BaumbartLogger.*;
import static at.htlAnich.Algos.wantsToExit;
import static at.htlAnich.Random.*;

public class Test {

	private static Scanner cin = new Scanner(System.in);


	public static class Time{
		protected long	timestampNano = 0,
						timestampMillis = 0;

		public void timestamp(){
			timestampMillis = System.currentTimeMillis();
			timestampNano = System.nanoTime();
		}

		public static Time calcTime(Time start, Time end){
			var t = new Time();
			t.timestampMillis = end.timestampMillis - start.timestampMillis;
			t.timestampNano = end.timestampNano - start.timestampNano;
			return t;
		}

		public static Time avgTime(Time t1, Time t2){
			var avg = new Time();
			avg.timestampMillis = (t1.timestampMillis+t2.timestampMillis)/2;
			avg.timestampNano = (t1.timestampNano+t2.timestampNano)/2;
			return avg;
		}

		public long getTimestampNano(){return this.timestampNano;}
		public long getTimestampMillis(){return this.timestampMillis;}
	}

	///////////////////////////////////////////////////

	//////////////////////////////////////
	//                                  //
	//        HELPER FUNCTIONS          //
	//                                  //
	//////////////////////////////////////

	public static void printResultsScreen(Counter c, Time time, int n){
		logf("Needed time: %d milliseconds%n" +
				"Needed time: %d nanoseconds%n" +
				"Comparisons: %d%n" +
				"Writes/Switches: %d%n" +
				"Recursive Depth: %d%n" +
				"Number of elements: %d%n" +
				"Number of this algorithm was called: %d%n",
				time.getTimestampMillis(), time.getTimestampNano(), c.getComparisons(), c.getWrites(),
				c.getRecursiveDepth(), n, c.getTimesAlgoWasCalled());
	}

	public static void printResultsScreen_Misc(Counter c){
		logf("Comparisons: %d%n" +
				"Writes: %d%n" +
				"Recursive depth of 0xfe: %d%n",
				c.getComparisons(), c.getWrites(), c.getRecursiveDepth());
	}

	public static String toLower(String s){
		return s.trim().toLowerCase();
	}

//////////////////////////////////////
//                                  //
//     PRIMARY SELECTION SCREENS    //
//                                  //
//////////////////////////////////////

	public static void printWelcomeScreen() {
		logf("%n%nWhat do you want to test?%n"+
				"[0] - Sorting algorithms%n"+
				"[1] - Search algorithms%n"+
				"[2] - Miscellaneous algorithms%n"+
				"[x] - Exits program%n");
		char c;
		c = cin.next().trim().toCharArray()[0];
		cin = cin.reset();

		// gosh... switch statements are so damn easier for this
		// glad to have them
		switch(c){
			case '0':
				printSelectionScreen_Sort();
				break;
			case '1':
				printSelectionScreen_Search();
				break;
			case '2':
				printSelectionScreen_Other();
				break;
			case 'X':
			case 'x':
				wantsToExit = true;
			default:
				return;
		}
	}
	public static void printSelectionScreen_Search(){
		logf("Which sorting algorithm dou you want to see?%n"+
				"[0] - Linear search%n"+
				"[1] - Binary search%n"+
				"[x] - Exits program%n");

		String c;
		c = cin.next();
		cin = cin.reset();
		c = toLower(c);

		if(c.compareTo("0")==0) {
			//linear();
		}else if(c.compareTo("1")==0){
			printSelectionScreen_BinarySearch();
		}else if(c.compareTo("x")==0){
			wantsToExit = true;
		}else{
			return;
		}
	}
	public static void printSelectionScreen_Sort(){
		logf("What do you want to test?%n"+
				"[0] - Bubble sort%n"+
				"[1] - Insertion sort%n"+
				"[2] - Selection sort%n"+
				"[3] - Quick sort%n"+
				"[4] - Merge sort%n"+
				"[x] - Exits program%n");

		String c;
		c = cin.next();
		cin = cin.reset();
		c = toLower(c);


		if(c.compareTo("0")==0) {
			bubble();
		}else if(c.compareTo("1")==0) {
			insertion();
		}else if(c.compareTo("2")==0) {
			printSelectionScreen_SelectionSort();
		}else if(c.compareTo("3")==0) {
			quick();
		}else if(c.compareTo("4")==0) {
			merge();
		}else if(c.compareTo("x")==0){
			wantsToExit = true;
		}else{
			return;
		}
		return;
	}
	public static void printSelectionScreen_Other(){
		logf("What do you want to test?%n"+
				"[0] - Faculty endrecursive%n"+
				"[1] - Sumfunction endrecursive%n"+
				"[2] - Power of a number%n"+
				"[x] - Exits program%n");

		String c;
		c = cin.next();
		cin = cin.reset();
		c = toLower(c);


		if(c.compareTo("0")==0){
			facultyRecursive();
		}else if(c.compareTo("1")==0){
			sumfunctionRecursive();
		}else if(c.compareTo("2")==0){
			pow();
		}else if(c.compareTo("x")==0){
			wantsToExit = true;
		}else{
			return;
		}
	}

//////////////////////////////////////
//                                  //
//     SEARCH SELECTION SCREEN      //
//                                  //
//////////////////////////////////////

	public static void  printSelectionScreen_BinarySearch(){

		logf("What do you want to test?%n"+
				"[0] - Normal%n"+
				"[1] - Recursive%n"+
				"[x] - Exits program%n");


		String c;
		c = cin.next();
		cin = cin.reset();
		c = toLower(c);


		if(c.compareTo("0")==0){
			binary();
		}else if(c.compareTo("1")==0){
			binaryRecursive();
		}else if(c.compareTo("x")==0){
			wantsToExit = true;
		}else{
			return;
		}
	}

//////////////////////////////////////
//                                  //
//     SORT SELECTION SCREEN        //
//                                  //
//////////////////////////////////////

	public static void printSelectionScreen_SelectionSort(){

		logf("What do you want to test?%n"+
				"[0] - Normal%n"+
				"[1] - Stable%n"+
				"[x] - Exits program%n");

		String c;
		c = cin.next();
		cin = cin.reset();
		c = toLower(c);

		if(c.compareTo("0")==0){
			selection();
		}else if(c.compareTo("1")==0){
			selectionStable();
		}else if(c.compareTo("x")==0){
			wantsToExit = true;
		}else{
			return;
		}
	}

//////////////////////////////////////
//                                  //
//     MISC SELECTION SCREEN        //
//                                  //
//////////////////////////////////////


//////////////////////////////////////
//                                  //
//       EXECUTION OF ALGOS         //
//                                  //
//////////////////////////////////////

	/*void bubble();
	void insertion();
	void selection();
	void selectionStable();
	void binary();
	void binaryRecursive();
	void faculty();
	void facultyRecursive();
	void sumfunction();
	void sumfunctionRecursive();
	void pow();
	void powRecursive();*/
	//using std::cerr;

	public static final int TIMES_TESTING = OFFICIAL_TEST_ARRAY_LENGTH/0xfe;

	public static void notImplementedErrorMsg(String s){
		errf("%s not implemented yet%n", s);
	}

	//////////////////////////////////////
	//                                  //
	//               SORT               //
	//                                  //
	//////////////////////////////////////

	public static void bubble(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			var arr = new MyArray(10000);
			initRandomArray(arr);

			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			AlgoExec.Sort.bubble(arr);
			end.timestamp();

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initRandomArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		var count = new Counter();
		AlgoExec.Sort.Count.bubble(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}
	public static void insertion(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			var arr = new MyArray(10000);
			initRandomArray(arr);

			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			AlgoExec.Sort.insertion(arr);
			end.timestamp();

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initRandomArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		var count = new Counter();
		AlgoExec.Sort.Count.insertion(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}
	public static void selection(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			var arr = new MyArray(10000);
			initRandomArray(arr);

			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			AlgoExec.Sort.selection(arr);
			end.timestamp();

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initRandomArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		var count = new Counter();
		AlgoExec.Sort.Count.selection(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}
	public static void selectionStable(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			var arr = new MyArray(10000);
			initRandomArray(arr);

			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			AlgoExec.Sort.selectionStable(arr);
			end.timestamp();

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initRandomArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		var count = new Counter();
		AlgoExec.Sort.Count.selectionStable(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}
	public static void quick(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			var arr = new MyArray(10000);
			initRandomArray(arr);

			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			AlgoExec.Sort.quick(arr);
			end.timestamp();

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initRandomArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		var count = new Counter();
		AlgoExec.Sort.Count.quick(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}
	public static void merge(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			var arr = new MyArray(10000);
			initRandomArray(arr);

			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			AlgoExec.Sort.merge(arr);
			end.timestamp();

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initRandomArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		var count = new Counter();
		AlgoExec.Sort.Count.merge(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}

//////////////////////////////////////
//                                  //
//              SEARCH              //
//                                  //
//////////////////////////////////////

	/**
	 * May insert a random element into the container, modifies the element to the random one and returns whether it was
	 * inserted or not.
	 * @param destArr The container, where the element could be added to.
	 * @param searchFor The element, that will be searched for and may gets inserted into the container.
	 * @return if the element was inserted for check.
	 */
	private static boolean insertElementToBeFound(MyArray destArr, int searchFor){
		var element = rand() % destArr.get(rand() % destArr.length());
		if(rand() % 101 >= 90){
			destArr.set(rand() % destArr.length(), element);
			return true;
		}
		return false;
	}

	public static void binary(){

		var wholeTime = new Time();
		logf("Measuring time...%n");
		for(int i = 0; i < TIMES_TESTING; ++i) {
			int searchFor = 0;
			var arr = new MyArray(10000);
			initSortedArray(arr);


			final var start = new Time();
			final var end = new Time();
			start.timestamp();
			//var ownIndex = algo::search::binary(arr, searchFor);
			end.timestamp();

			//var correctIndex = arr.

			logf("step %d of %d done%n", i+1, TIMES_TESTING);

			wholeTime = Time.avgTime(wholeTime, Time.calcTime(start, end));

			initSortedArray(arr);
		}

		logf("Time measured, measuring steps...%n");

		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		arr = copyOfficialTestArray();
		arr.sort();
		var count = new Counter();
		AlgoExec.Sort.Count.selectionStable(arr, count);


		printResultsScreen(count, wholeTime, OFFICIAL_TEST_ARRAY_LENGTH);
		count.clear();
		//delete count;
		//delete arr;
	}
	public static void binaryRecursive(){notImplementedErrorMsg("BinaryRecursive");}

//////////////////////////////////////
//                                  //
//          MISCELLANEOUS           //
//                                  //
//////////////////////////////////////

	public static void facultyRecursive(){
		var arr = new int[TIMES_TESTING];
		for(int i = 0; i < TIMES_TESTING; ++i) {
			arr[i] = AlgoExec.Misc.faculty(i);
		}
		var c = new Counter();
		AlgoExec.Misc.Count.faculty(0xfe, c);
		printResultsScreen_Misc(c);
	}
	public static void sumfunctionRecursive(){
		var arr = new int[TIMES_TESTING];
		for(int i = 0; i < TIMES_TESTING; ++i) {
			arr[i] = AlgoExec.Misc.sumFunction(i);
		}
		var c = new Counter();
		AlgoExec.Misc.Count.sumFunction(0xfe, c);
		printResultsScreen_Misc(c);
	}
	public static void pow(){
		var arr = new int[TIMES_TESTING];
		for(int i = 0; i < TIMES_TESTING; ++i) {
			arr[i] = AlgoExec.Misc.pow(0xfe, i);
		}
		var c = new Counter();
		AlgoExec.Misc.Count.pow(0xfe, 0xfe, c);
		printResultsScreen_Misc(c);
	}
}
