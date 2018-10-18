package com.company;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static class output {
        int first_in;
        int last_in;
        int sum;

        public output(int first_in, int last_in, int sum) {
            this.first_in = first_in;
            this.last_in = last_in;
            this.sum = sum;
        }

        public output() {
            this.first_in = -1;
            this.last_in = -1;
            this.sum = 0;
        }
    }

    public static output maximum_subarray(ArrayList<Integer> array, int first_in, int last_in) {
        output o;
        System.out.println("****");
        int length = last_in - first_in + 1;
        System.out.println("First: " + first_in + "\nLast: " + last_in + "\n");
        System.out.println("Length: " + length+"\n");
        if (length != 1) {
            int mid = length / 2 + first_in;
            output left_max = maximum_subarray(array, first_in, mid-1);
            output right_max = maximum_subarray(array, mid, last_in);
            output mid_max = find_max_mid(array, first_in, last_in, mid);
            System.out.println("Considered subarray:\t"+array.subList(first_in,last_in+1));
            System.out.println("Maximal left:\t"+array.subList(left_max.first_in,left_max.last_in+1)+" with sum: "+left_max.sum);
            System.out.println("Maximal right:\t"+array.subList(right_max.first_in,right_max.last_in+1)+" with sum: "+right_max.sum);
            System.out.println("Maximal mid:\t"+array.subList(mid_max.first_in,mid_max.last_in+1)+" with sum: "+mid_max.sum);
            o = (left_max.sum > right_max.sum) ? left_max : right_max;
            o = (o.sum > mid_max.sum) ? o : mid_max;
            System.out.println("Chosen maximal:\t"+array.subList(o.first_in,o.last_in+1));
        } else {
            o = new output(first_in, last_in, array.get(first_in));

        }

        return o;
    }

    public static output find_max_mid(ArrayList<Integer> array, int first_in, int last_in, int mid) {
        //left
        int left_l = (mid - 1) - first_in + 1;
        output o = new output();
        int sum_max_r = 0;
        int sum_max = 0;
        if (left_l <= 1) {
            o.first_in = first_in;
            sum_max=array.get(first_in);
        } else {
            int sum = array.get(mid - 1);
            o.first_in = mid - 1;
            sum_max = sum;
            for (int i = mid - 2; i >= first_in; i--) {
                sum += array.get(i);
                if (sum > sum_max) {
                    o.first_in = i;
                    sum_max = sum;
                }
            }
        }

        //right
        int right_l = last_in - mid + 1;
        if (right_l <= 1) {
            o.last_in = last_in;
            sum_max_r=array.get(last_in);
        } else {
            int sum = array.get(mid);
            o.last_in = mid;
            sum_max_r = sum;
            for (int i = mid + 1; i <= last_in; i++) {
                sum += array.get(i);
                if (sum > sum_max_r) {
                    o.last_in = i;
                    sum_max_r = sum;
                }
            }
        }
        o.sum = sum_max + sum_max_r;
        return o;
    }

    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<>(Arrays.asList(13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7));
        output o = maximum_subarray(array, 0, array.size() - 1);
        System.out.println("Maximal subarray: " + array.subList(o.first_in, o.last_in + 1));
        System.out.println("Sum: " + o.sum);
    }
}

