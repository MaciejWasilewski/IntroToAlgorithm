package com.example;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    static class solution {
        protected int numberOfMultiplications;
        protected String multiplicationScheme;
    }

    static class matrix {
        int dim1;
        int dim2;
        public matrix(int dim1, int dim2)
        {
            this.dim1=dim1;
            this.dim2=dim2;
        }


    }

    public static solution matrixMultiplicationDynamic(ArrayList<matrix> matrices) {
        int n = matrices.size();
//        every element of m and partition is initialized to 0!
        int[][] m = new int[n][n];
        int[][] partition=new int[n][n];
        for(int i=0;i<n;i++)
        {
            m[i][i]=0;
        }
        for(int diag=1;diag<n;diag++)
        {
            for(int elem=0;elem<n-diag;elem++)
            {
                int i=elem;
                int j=diag+elem;
                int price=Integer.MAX_VALUE;
                int part=0;
                for(int k=i;k<j;k++)
                {
                    int tempSum=m[i][k]+m[k+1][j]+matrices.get(i).dim1*matrices.get(k).dim2*matrices.get(j).dim2;
                    if(tempSum<price)
                    {
                        price=tempSum;
                        part=k;
                    }
                }
                m[i][j]=price;
                partition[i][j]=part;
//                for (int[] x:m
//                     ) {
//                    System.out.println(Arrays.toString(x));
//                }
//                System.out.println("\n\n");

            }
        }

        StringBuilder builder=new StringBuilder(3*n);
        scheme(builder,partition,0,n-1);
        solution sol=new solution();
        sol.numberOfMultiplications=m[0][n-1];
        sol.multiplicationScheme=builder.toString();
        return sol;
    }
    static void scheme(StringBuilder builder, int[][] s, int i, int j)
    {

        if(i==j)
        {
            builder.append("A_");
            builder.append(i);
        }
        else
        {
            int partition=s[i][j];
            builder.append("(");
            scheme(builder, s, i,partition);
            builder.append("*");
            scheme(builder, s, partition+1,j);
            builder.append(")");
        }
    }
    public static void main(String[] args) {

        matrix[] a={new matrix(30,35),new matrix(35,15),new matrix(15,5),new matrix(5,10),new matrix(10,20),
                new matrix(20,25)};
        ArrayList<matrix> matrices=new ArrayList<>(Arrays.asList(a));
        solution sol=matrixMultiplicationDynamic(matrices);
        System.out.println(sol.multiplicationScheme);
        System.out.println(sol.numberOfMultiplications);
    }
}
