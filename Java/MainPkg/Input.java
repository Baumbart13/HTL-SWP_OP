package MainPkg;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Input {

    static public int random(){
        return 1+(int)(Math.random()*4654216);
    }

    static public int random(int min, int max){
        return (int)(min + (max-min) * Math.random());
    }

    static public int[] randIntArr(int length){
        int out[] = new int[length];
        for(int i = 0; i < length; ++i){
            out[i] = random();
        }
        return out;
    }

    static public int[] randIntArr(){
        return randIntArr(random());
    }

    static public int[] testRandIntArr(){
        int[] arr = randIntArr();
        arr[random(0, arr.length-1)] = 6;
        return arr;
    }

    static public int[] sortedRandIntArr(){
        return sortedRandIntArr(random());
    }

    static public int[] sortedRandIntArr(int length){
        int[] arr = randIntArr(length);
        Arrays.sort(arr);
        return arr;
    }

    static final int[] intArray0 = new int[]          {66,831,42,69,550,250,6,12,240,160,26,75,312,59,4141,525,510,74,1840,60,46,7015,91,1};
    static final double[] floatArray = new double[]  {66.831,42.69,550.250,6.12,240.160,26.75,312.59,4141.525,510.74,1840.60,46.7015,91.1};
    static final char[] charArray = new char[]       {66,83,142,6,95,50,250,6,12,240,160,26,75,3,12,59,4,141,52,5,51,0,74,18,40,60,46,70,15,91,1};
}
