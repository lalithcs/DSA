package ALGORITHMS.DIVIDE_AND_CONQUER;
import java.util.Scanner;
/**
 * Author: Challa Saraswathi Lalith
 * Contact at:lalithcspersonal@gmail.com
 * Date:16-02-2024
 * Project: Data Stuctures and Algorithms
 */
public class quick_sort {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the unsorted array:");
        String[] input=in.nextLine().split("\\s+");
        int[] array = new int[input.length];

        for (int i = 0; i < input.length; i++) {
            array[i] = Integer.parseInt(input[i]);
        }
        quickSort(array, 0, array.length - 1);
        System.out.println("The sorted array is:");
        for (int num : array) {
            System.out.print(num + " ");
        }
    }

    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }

    public static int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        return i + 1;
    }
}

