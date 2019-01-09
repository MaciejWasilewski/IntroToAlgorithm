package com.example;

import java.util.Arrays;

public class Main {

    static class solution {
        int length;
        String subsequence;

        public solution(int length, String subsequence) {
            this.length = length;
            this.subsequence = subsequence;
        }
    }

    enum directions {
        up,
        left,
        skew
    }

    static void printSubsequence(StringBuilder builder, int i, int j, directions[][] dirs, String s1) {
        int new_i = (dirs[i][j] == directions.left) ? i : i - 1;
        int new_j = (dirs[i][j] == directions.up) ? j : j - 1;
        if (new_i >= 0 && new_j >= 0) {
            printSubsequence(builder, new_i, new_j, dirs, s1);
        }
        if (dirs[i][j] == directions.skew) {
            builder.append(s1.charAt(i));
        }
    }

    static solution longestSubsequence(String s1, String s2) {
        int[][] length = new int[s1.length() + 1][s2.length() + 1];
        directions[][] dirs = new directions[s1.length()][s2.length()];
        for (int col = 1; col < s2.length() + 1; col++) {
            for (int row = 1; row < s1.length()+1; row++) {
                if (s1.charAt(row - 1) == s2.charAt(col - 1)) {
                    System.out.println(s1.charAt(row - 1));
                    System.out.println(s2.charAt(col - 1));
                    length[row][col] = length[row - 1][col - 1] + 1;
                    dirs[row-1][col-1] = directions.skew;
                } else {
                    if (length[row - 1][col] > length[row][col - 1]) {
                        length[row][col] = length[row - 1][col];
                        dirs[row - 1][col - 1] = directions.up;
                    } else {
                        length[row][col] = length[row][col - 1];
                        dirs[row - 1][col - 1] = directions.left;
                    }
                }
                for (int[] x : length
                ) {
                    System.out.println(Arrays.toString(x));
                }
                System.out.println("\n\n");
            }
        }

        StringBuilder builder = new StringBuilder();
        printSubsequence(builder, s1.length() - 1, s2.length() - 1, dirs, s1);
        return new solution(length[s1.length()][s2.length()], builder.toString());
    }

    public static void main(String[] args) {
        String s1 = "abcbdab";
        String s2 = "bdcaba";
        solution sol = longestSubsequence(s1, s2);
        System.out.println(sol.subsequence);
        System.out.println(sol.length);

    }
}
