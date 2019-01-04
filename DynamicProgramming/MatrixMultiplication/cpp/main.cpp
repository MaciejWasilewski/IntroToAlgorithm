#include <iostream>
#include <vector>
#include <cmath>
struct matrix_dimension {
    unsigned int dim1;
    unsigned int dim2;
};

void print_multiply_chain(std::vector<std::vector<unsigned long>> breaks, unsigned long i, unsigned long j)
{
//    std::cout<<"\n"<<i<<"\t"<<j<<"\n";
//    std::cout<<"First matrix: "<<i<<", last matrix: "<<j<<"\n";
    if(i==j)
    {
        std::cout<<"A_"<<i;
    }
    else
    {
 std::cout<<"(";
//        std::cout<<"Multiplication after the "<<breaks[j-i][i]<<". matrix."<<"\n";
        print_multiply_chain(breaks, i,breaks[j-i][i]);
        std::cout<<"*";
        print_multiply_chain(breaks, breaks[j-i][i]+1,j);
std::cout<<")";
    }


}

int multiplication_cost(std::vector<matrix_dimension> matrices) {
    std::vector<std::vector<int>> costs;
    std::vector<std::vector<unsigned long>> breaks;
    costs.resize(matrices.size());
    breaks.resize(matrices.size());
    for (int i = 0; i < matrices.size(); i++) {
        costs[i].resize(matrices.size() - i);
    }
    for (int i = 0; i < matrices.size(); i++) {
        breaks[i].resize(matrices.size() - i);
    }
    for (int item = 0; item < matrices.size(); item++) {
        costs[0][item] = 0;
    }
    for (int diag = 1; diag < matrices.size(); diag++) {
        for (unsigned long item = 0; item < costs[diag].size(); item++) {
//            std::cout<<"Diag: "<<diag<<", item: "<<item<<"\n";
            int optim = INT32_MAX;
            unsigned long break2=0;
//            std::cout << diag << " choices are being considered\n";
            for (int k = 0; k < diag; k++) {
//                std::cout<<"k "<<k<<"\n";
//                std::cout<<"Costs: "<<costs[k][item]<<"\t"<<costs[diag - k - 1][item+k + 1]<<"\n";
//                std::cout<<"Dimensions: "<<matrices[item].dim1<<"\t"<<matrices[item+k+1].dim1<<"\t"<< matrices[diag + item].dim2<<"\n";
                int m_temp = costs[k][item] + costs[diag - k - 1][item+k + 1] +
                             matrices[item].dim1 * matrices[item+k+1].dim1 * matrices[diag + item].dim2;
                if (m_temp < optim) {
                    optim = m_temp;
                    break2=k+item;
                }
            }
            costs[diag][item] = optim;
            breaks[diag][item] = break2;
//            std::cout << optim << "\t";
        }
        for (int item = 0; item < matrices.size(); item++) {
            for (int diag2 = 0; diag2 <=std::min(diag,(int)matrices.size()-item-1); diag2++) {
                std::cout << breaks[diag2][item]<<"\t";
            }
            std::cout<<"\n";
        }
        std::cout << "\n";
    }
print_multiply_chain(breaks,0,matrices.size()-1);
    std::cout<<"\n";
    return costs.back().back();
}

int main() {
    std::vector<matrix_dimension> matrices;
    matrices.push_back((struct matrix_dimension) {.dim1=30, .dim2=35});
    matrices.push_back((struct matrix_dimension) {.dim1=35, .dim2=15});
    matrices.push_back((struct matrix_dimension) {.dim1=15, .dim2=5});
    matrices.push_back((struct matrix_dimension) {.dim1=5, .dim2=10});
    matrices.push_back((struct matrix_dimension) {.dim1=10, .dim2=20});
    matrices.push_back((struct matrix_dimension) {.dim1=20, .dim2=25});
    std::cout << multiplication_cost(matrices) << std::endl;
    return 0;
}