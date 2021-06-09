package _01_BinarySearch;

import java.util.Arrays;

public class Search {
    public static int binary(int[] array, int searching){

        int left = 0;
        int right = array.length-1;

        while(left <= right){
            // adjust middle
            int middle = left + ((right - left) / 2);

            if(array[middle] == searching){
                return middle;
            }
            if(array[left] == searching){
                return left;
            }
            if(array[right] == searching){
                return right;
            }

            if(searching < array[middle]){
                right = middle-1;
            }else{
                left = middle+1;
            }
        }

        // Not found
        return -1;
    }

    public static int sequential(int[] array, int searching){

        for(int i = 0; i < array.length; ++i){
            if(array[i] == searching){
                return i;
            }
        }

        // Not found
        return -1;
    }
}
