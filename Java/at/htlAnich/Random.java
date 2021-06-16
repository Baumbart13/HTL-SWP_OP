package at.htlAnich;

import java.util.LinkedList;
import java.util.List;

public class Random {
	public static final int OFFICIAL_TEST_ARRAY_LENGTH = 10000;
	public static MyArray OFFICIAL_TEST_ARRAY = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);

	public static void initRandomArray(MyArray destination){
		for(int i = 0; i < destination.length(); ++i){
			destination.set(i, getRandomElement());
		}
	}

	public static void initSortedArray(MyArray destination){
		for(int i = 0; i < destination.length(); ++i){
			destination.set(i, getRandomElement() % (i<<1));
		}
		destination.sort();
	}

	public static MyArray initTestArray(){
		var arr = new MyArray(OFFICIAL_TEST_ARRAY_LENGTH);
		for(int i = 0; i < OFFICIAL_TEST_ARRAY_LENGTH; ++i){
			arr.set(i, getUniqueRandomElement());
		}
		return arr;
	}

	public static int getRandomElement(){
		return rand.nextInt(Integer.MAX_VALUE-2);
	}

	public static int rand(){ return getRandomElement(); }

	private static List<Integer> usedValues = new LinkedList<Integer>();
	private static java.util.Random rand = new java.util.Random();
	public static int getUniqueRandomElement(){
		int randomElement = 0;
		do{
			randomElement = rand.nextInt(Integer.MAX_VALUE-2);
		}while(usedValues.contains(Integer.valueOf(randomElement)));

		usedValues.add(randomElement);
		return randomElement;
	}

	public static MyArray copyOfficialTestArray(){
		var arr = new MyArray(OFFICIAL_TEST_ARRAY.length());
		for(int i = 0; i < arr.length(); ++i){
			arr.set(i, OFFICIAL_TEST_ARRAY.get(i));
		}
		return arr;
	}
}
