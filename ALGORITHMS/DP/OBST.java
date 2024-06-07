package ALGORITHMS.DP;

import java.util.Scanner;

public class OBST {
    public static final int MAX = 10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] ele = new String[MAX];
        int[][] w = new int[MAX][MAX];
        int[][] c = new int[MAX][MAX];
        int[][] r = new int[MAX][MAX];
        int[] p = new int[MAX];
        int[] q = new int[MAX];
        int temp = 0, root, min, min1, n;
        int i, j, k, b;

        System.out.print("Enter the number of elements: ");
        n = scanner.nextInt();

        for (i = 1; i <= n; i++) {
            System.out.print("Enter the Element of " + i + ": ");
            p[i] = scanner.nextInt();
        }

        for (i = 1; i <= n; i++) {
            System.out.print("Enter the Probability of " + i + ": ");
            q[i] = scanner.nextInt();
        }
        for(int z=0;z<=n;z++){
            System.out.println(q[z]);
        }
        System.out.println("W\t\tC\t\tR");
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                if (i == j) {
                    w[i][j] = q[i];
                    c[i][j] = 0;
                    r[i][j] = 0;
                    System.out.println("W[" + i + "][" + j + "]: " + w[i][j] + "\tC[" + i + "][" + j + "]: " + c[i][j] + "\tR[" + i + "][" + j + "]: " + r[i][j]);
                }
            }
        }

        System.out.println();
        for (b = 0; b < n; b++) {
            for (i = 0, j = b + 1; j < n + 1 && i < n + 1; j++, i++) {
                if (i != j && i < j) {
                    w[i][j] = p[j] + q[j] + w[i][j - 1];
                    min = Integer.MAX_VALUE;
                    for (k = i + 1; k <= j; k++) {
                        min1 = c[i][k - 1] + c[k][j] + w[i][j];
                        if (min > min1) {
                            min = min1;
                            temp = k;
                        }
                    }
                    c[i][j] = min;
                    r[i][j] = temp;
                }
                System.out.println("W[" + i + "][" + j + "]: " + w[i][j] + "\tC[" + i + "][" + j + "]: " + c[i][j] + "\tR[" + i + "][" + j + "]: " + r[i][j]);
            }
            System.out.println();
        }

        System.out.println("Minimum cost = " + c[0][n]);
        root = r[0][n];
        System.out.println("Root  = " + root);
        
        scanner.close();
    }
}
