package MainPkg;

import _01_BinarySearch.Search;

import java.math.BigInteger;
import java.util.Arrays;

public class HTL_SWP_OP {
    private static final int searchForThis = 6;
    private static final int noIterations = 1000000;
    private static final int length = 10000;

    public static int isSorted(int[] arr){
        for(int i = 1; i < arr.length; ++i){
            if(arr[i-1] > arr[i]){
                return -1;
            }
        }
        return 1;
    }

    public static BigInteger timestamp_Nano(){
        return BigInteger.valueOf(System.nanoTime());
    }

    public static void main(String[] args) {
        int[] copy = Input.intArray0.clone();
        Arrays.sort(copy);

        BigInteger start;
        BigInteger end;
        BigInteger time_BinaryOwn = new BigInteger("0");
        BigInteger time_Sequential = new BigInteger("0");
        BigInteger time_BinaryJava = new BigInteger("0");
        long noSuccess_BinaryOwn = 0;
        long noSuccess_Sequential = 0;
        long noSuccess_BinaryJava = 0;

        for(int i = 0; i < noIterations; ++i){

            start = timestamp_Nano();
            if(Search.sequential(copy, searchForThis) < 0){
                ++noSuccess_Sequential;
            }
            end = timestamp_Nano();

            time_Sequential = time_Sequential.add(end.subtract(start)).divide(BigInteger.TWO);

            start = timestamp_Nano();
            if(Search.binary(copy, searchForThis) < 0){
                ++noSuccess_BinaryOwn;
            }
            end = timestamp_Nano();

            time_BinaryOwn = time_BinaryOwn.add(end.subtract(start)).divide(BigInteger.TWO);

            start = timestamp_Nano();
            if(Arrays.binarySearch(copy, searchForThis) < 0){
                ++noSuccess_BinaryJava;
            }
            end = timestamp_Nano();

            time_BinaryJava = time_BinaryJava.add(end.subtract(start)).divide(BigInteger.TWO);

            copy = Input.randIntArr(length);
            Arrays.sort(copy);
        }


        System.out.println("Binär eigen:\t" + time_BinaryOwn.toString() + "ms" + System.lineSeparator() + "Failures:\t\t" + noSuccess_BinaryOwn);
        System.out.println("Binär Java:\t\t" + time_BinaryJava.toString() + "ms" + System.lineSeparator() + "Failures:\t\t" + noSuccess_BinaryJava);
        System.out.println("Sequentiell:\t" + time_Sequential.toString() + "ms" + System.lineSeparator() + "Failures:\t\t" + noSuccess_Sequential);
    }
}
