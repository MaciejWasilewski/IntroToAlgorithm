#include <iostream>
#include <cmath>
#include <vector>

struct solution {
    int price;
    std::vector<int> cuts;
};

solution cut_rod_dynamic(std::vector<int>price_array, int length) {
    std::vector<solution> optimal_prices;
    optimal_prices.resize((unsigned int)length);
    for (int i = 0; i < length; i++) {
        int price = 0;
        std::vector<int> cuts;
        if (i < price_array.size()) {
            price = price_array[i];
            cuts.push_back(i+1);
//            std::cout<<"Cut candidate: "<<cuts[cuts.size()-1]<<"\n";
        }
        for (int j = 0; j < std::min((int)price_array.size(), i); j++) {
            if (price < price_array[j] + optimal_prices[i - j - 1].price) {
                price = price_array[j] + optimal_prices[i - j - 1].price;
                cuts.clear();
                cuts.resize(optimal_prices[i - j - 1].cuts.size());
                std::copy(optimal_prices[i - j - 1].cuts.begin(), optimal_prices[i - j - 1].cuts.end(), cuts.begin());
                cuts.push_back(j+1);
//                std::cout<<"Found better cut with price: "<<price<<"\n"<<"Number of cuts: "<<cuts.size()<<"\n";
            }
        }
        solution res;
        res.price=price;
        res.cuts=cuts;
        optimal_prices[i]=res;
//        for(int k=i;k<=i;k++)
//        {
//            std::cout <<"Optimal cuts for length = "<<k+1<<"\n";
//            for(int z=0;z< optimal_prices[k].cuts.size();z++)
//            {
//                std::cout <<optimal_prices[k].cuts[z]<<"\t";
//            }
//            std::cout <<"\n";
//        }
    }
    return optimal_prices[length-1];
}

int main() {
    std::vector<int> prices={1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for(int i=1;i<21;i++) {
        solution res = cut_rod_dynamic(prices, i);
        std::cout << "Optimal cut for length " << i<<":\t" << res.price << std::endl<<"Optimal cuts:\n";
        for (int cut: res.cuts) {
            std::cout << cut << "\t";
        }
        std::cout << "\n";
    }
}