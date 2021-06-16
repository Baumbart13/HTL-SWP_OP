package at.htlAnich;

import java.util.Arrays;

public class MyArray {
	protected int arr[];
	protected int length = 0;

	public MyArray(int size){
		this.arr = new int[size];
		this.length = size;
	}

	public void sort(){
		var temp = Arrays.stream(arr).sorted();
		arr = temp.toArray();
	}

	public int length(){
		return this.length;
	}

	public int search(int val){
		// simple double sided sequentialSearch, just to make sure there is definitely the value inside
		int lowerIndex = 0;
		int upperIndex = this.length-1;

		while(lowerIndex <= upperIndex){
			if(this.arr[lowerIndex] == val){
				return lowerIndex;
			}
			if(this.arr[upperIndex] == val){
				return upperIndex;
			}
			++lowerIndex;
			--upperIndex;
		}
		return -1;
	}

	public int get(int i){
		return this.arr[i];
	}

	public void set(int i, int x){
		this.arr[i] = x;
	}

	/**
	 Swaps 2 places. Unstable
	 @param i the first index.
	 @param j the second index.
	 */
	public void swap(int i, int j){
		var temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
