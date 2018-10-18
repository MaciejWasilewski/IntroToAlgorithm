#include <iostream>
using namespace std;

int * selectionSort(int * table, int length)
{

    for(int i=0;i<length-1;i++)
    {
        int min=i;
        for(int j=i+1;j<length;j++)
        {
            if(table[min]>table[j])
            {
                min=j;
            }
        }
        int temp=table[i];
        table[i]=table[min];
        table[min]=temp;
        for(int k=0;k<length;k++)
        {
            cout<<table[k]<<"\t";

        }
        cout<<"\n";
    }
    return table;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int * table=new int[8];
    table[0]=3;
    table[1]=2;
    table[2]=1;
    table[3]=0;
    table[4]=3;
    table[5]=2;
    table[6]=1;
    table[7]=0;
    table=selectionSort(table, 8);
    delete[] table;
    return 0;
}