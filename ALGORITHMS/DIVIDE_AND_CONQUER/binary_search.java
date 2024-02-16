package ALGORITHMS.DIVIDE_AND_CONQUER;


/**
 * Author: Challa Saraswathi Lalith
 * Contact at:lalithcspersonal@gmail.com
 * Date:16-02-2024
 * Project: Data Stuctures and Algorithms
 */
import java.sql.SQLOutput;
import java.util.Scanner;

public class binary_search {

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

        int[] result = searchRange(nums, target);
        System.out.println("The numbers rightmost and leftmost occurences are:");
        System.out.println("[" + result[0] + ", " + result[1] + "]");
    }

    public static int[] searchRange(int[] nums, int target) {
        int[] result = new int[2];
        result[0] = -1; // Initialize start position
        result[1] = -1; // Initialize end position
        // Modified binary search for leftmost occurrence
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                right = mid - 1; // Search for leftmost occurrence in left subarray
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // Modified binary search for rightmost occurrence
        left = result[0]; // Start searching from the leftmost occurrence
        right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[1] = mid;
                left = mid + 1; // Search for rightmost occurrence in right subarray
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}
