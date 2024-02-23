package ALGORITHMS.DIVIDE_AND_CONQUER;

import java.util.Scanner;

/**
 * Author: Challa Saraswathi Lalith
 * Contact at:lalithcspersonal@gmail.com
 * Date:23-02-2024
 * Project: Data Stuctures and Algorithms
 */
public class BinarySearchRecursive {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter the number of elements: ");
        int numsSize = scanner.nextInt();

        // Check the constraints for numsSize
        if (numsSize < 0 || numsSize > 100000) {
            System.out.println("Invalid input for the number of elements.");
            return; // Exit the program with an error status
        }

        int[] nums = new int[numsSize];
        System.out.println("Enter the elements in non-decreasing order:");
        for (int i = 0; i < numsSize; i++) {
            nums[i] = scanner.nextInt();
            // Check the constraints for nums[i]
            if (nums[i] < -1000000000 || nums[i] > 1000000000) {
                System.out.println("Invalid input for element " + (i + 1) + ".");
                return; // Exit the program with an error status
            }
        }

        System.out.print("Enter the target value: ");
        int target = scanner.nextInt();
        // Check the constraints for target
        if (target < -1000000000 || target > 1000000000) {
            System.out.println("Invalid input for the target value.");
            return; // Exit the program with an error status
        }

        int index = binarySearch(nums, target);
        if (index != -1) {
            System.out.println("Element " + target + " found at index " + index);
        } else {
            System.out.println("Element " + target + " not found in the array.");
        }
    }

    public static int binarySearch(int[] arr, int target) {
        return binarySearchRecursive(arr, target, 0, arr.length - 1);
    }

    public static int binarySearchRecursive(int[] arr, int target, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                return binarySearchRecursive(arr, target, mid + 1, high);
            } else {
                return binarySearchRecursive(arr, target, low, mid - 1);
            }
        }
        return -1;
    }
}
