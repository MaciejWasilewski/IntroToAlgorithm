package com.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    static ArrayList<Integer> price = new ArrayList<>(Arrays.asList(0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30));

    private static class solution {
        int price;
        ArrayList<Integer> cuts;

        public solution() {
            this(0);
        }

        public solution(int price) {
            this.price = price;
        }

        public solution(int price, ArrayList<Integer> cuts) {
            this.price = price;
            this.cuts = cuts;
        }

        @Override
        public String toString() {
            StringBuilder cuts;
            cuts = new StringBuilder();
            for (int i = 0; i < this.cuts.size(); i++) {
                cuts.append(this.cuts.get(i));
                cuts.append(" ");
            }
            return "Price=" + price + "\n" + "Cuts:\t" + cuts.toString();
        }
    }

    static solution cut_rod(ArrayList<Integer> cut_prices, int length) {
        solution full_sol = new solution();
        int q = 0;
        int cut = 0;
        ArrayList<Integer> cuts = new ArrayList<>();
        if (length < cut_prices.size()) {
            q = cut_prices.get(length);
            cut = length;
            cuts = new ArrayList<>(Arrays.asList(cut));
        }

        for (int i = 1; i < Math.min(length + 1, cut_prices.size()); i++) {
            solution temp_sol = cut_rod(cut_prices, length - i);
            int temp = cut_prices.get(i) + temp_sol.price;
//            System.out.printf("Checking "+i+" cut\n");
            if (q < temp) {
                cut = i;
                q = temp;
                cuts = new ArrayList<>(temp_sol.cuts);
                cuts.add(cut);
            }
        }
        return new solution(q, cuts);
    }

    static solution dynamic_cut_rod(ArrayList<Integer> cut_prices, int length, ArrayList<solution> optimal_solutions) {
        if (optimal_solutions.get(length) == null) {
            solution full_sol = new solution();
            int q = 0;
            int cut = 0;
            ArrayList<Integer> cuts = new ArrayList<>();
            if (length < cut_prices.size()) {
                q = cut_prices.get(length);
                cut = length;
                cuts = new ArrayList<>(Arrays.asList(cut));
            }

            for (int i = 1; i < Math.min(length + 1, cut_prices.size()); i++) {
                solution temp_sol = dynamic_cut_rod(cut_prices, length - i, optimal_solutions);
                int temp = cut_prices.get(i) + temp_sol.price;
//            System.out.printf("Checking "+i+" cut\n");
                if (q < temp) {
                    cut = i;
                    q = temp;
                    cuts = new ArrayList<>(temp_sol.cuts);
                    cuts.add(cut);
                }
            }
            optimal_solutions.set(length, new solution(q, cuts));
        }
        return optimal_solutions.get(length);
    }

    static solution dynamic_cut_rod_bottomup(ArrayList<Integer> cut_prices, int length) {
        ArrayList<solution> optimal_solutions = new ArrayList<>(Arrays.asList(new solution[length + 1]));
        optimal_solutions.set(0, new solution(0));
        for (int i = 1; i <= length; i++) {
            solution partial_sol = new solution();
            int q = 0;
            int cut = 0;
            ArrayList<Integer> cuts = new ArrayList<>();
            if (i < cut_prices.size()) {
                q = cut_prices.get(i);
                cut = i;
                cuts = new ArrayList<>(Arrays.asList(cut));
//                System.out.println("Whole rod price: "+q+"\n");
            }
            for (int j = 1; j < Math.min(i,cut_prices.size()); j++) {
//                System.out.println(i+"\t"+j+"\n");
//                System.out.println(optimal_solutions.get(i-j).price);
                int temp = cut_prices.get(j) + optimal_solutions.get(i - j).price;
//                System.out.println(temp+"\n");
//                System.out.println(q+"\n");
                if (q < temp) {

                    cut = j;
                    q = temp;
                    cuts = new ArrayList<>(optimal_solutions.get(i - j).cuts);
                    cuts.add(cut);
                }

            }
//            System.out.println(i+"\t"+q+"\n");
            optimal_solutions.set(i,new solution(q, cuts));

        }
        return optimal_solutions.get(length);
    }

    public static void main(String[] args) {
        ArrayList<solution> optimals;
        for (int i = 1; i <= 20; i++) {
            optimals = new ArrayList<>(Arrays.asList(new solution[30]));
            solution sol = dynamic_cut_rod_bottomup(price, i);
            System.out.printf("Optimal solution " + i + " is " + sol + "\n");
        }
    }
}
