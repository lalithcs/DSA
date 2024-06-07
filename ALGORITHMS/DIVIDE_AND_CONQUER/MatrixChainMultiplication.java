package ALGORITHMS.DIVIDE_AND_CONQUER;

/**
 * Author: Challa Saraswathi Lalith
 * Contact at:lalithcspersonal@gmail.com
 * Date:26-04-2024
 * Project: Data Stuctures and Algorithms
 */
import java.util.Scanner;

public class MatrixChainMultiplication {
    static final int INFY = 999;
    static long[][] m = new long[20][20];
    static int[][] s = new int[20][20];
    static int[] p = new int[20];
    static int n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, i, j;

        System.out.print("Enter the number of elements: ");
        n = scanner.nextInt();

        for (i = 1; i <= n; i++)
            for (j = i + 1; j <= n; j++) {
                m[i][i] = 0;
                m[i][j] = INFY;
                s[i][j] = 0;
            }

        System.out.println("\nEnter the dimensions:");
        for (k = 0; k <= n; k++) {
            System.out.printf("P%d: ", k);
            p[k] = scanner.nextInt();
        }

        matMultiply();

        System.out.println("\nCost Matrix M:");
        for (i = 1; i <= n; i++)
            for (j = i; j <= n; j++)
                System.out.printf("m[%d][%d]: %d\n", i, j, m[i][j]);

        System.out.println("\nMatrix S for k values:");
        for (i = 1; i <= n; i++)
            for (j = i; j <= n; j++)
                System.out.printf("s[%d][%d]: %d\n", i, j, s[i][j]);

        i = 1;
        j = n;
        System.out.print("\nMULTIPLICATION SEQUENCE : ");
        printOptimal(i, j);
    }

    static void printOptimal(int i, int j) {
        if (i == j)
            System.out.printf(" A%d ", i);
        else {
            System.out.print(" ( ");
            printOptimal(i, s[i][j]);
            printOptimal(s[i][j] + 1, j);
            System.out.print(" ) ");
        }
    }

    static void matMultiply() {
        long q;
        int k;
        for (int i = n; i > 0; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j)
                    m[i][j] = 0;
                else {
                    for (k = i; k < j; k++) {
                        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                        if (q < m[i][j]) {
                            m[i][j] = q;
                            s[i][j] = k;
                        }
                    }
                }
            }
        }
    }
}
