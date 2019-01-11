#include <iostream>
#include <string>
#include <vector>
#include <cmath>

enum dir {
    up,
    left,
    upleft
};

class directions {


public:
    dir dirMember;

    directions() {
        dirMember = dir::left;
    }

};

struct solution {
    int length;
    std::string subsequence;
};

void retrieve_lcs(std::string *str, std::string *s1, std::vector<std::vector<directions >> *dirs, size_t i, size_t j);

solution LCS_dynamic(std::string s1, std::string s2) {
    auto m = (size_t) s1.length();
    auto n = (size_t) s2.length();
    std::vector<std::vector<int>> lcs;
    std::vector<std::vector<directions >> dirs;
    lcs.resize(m + 1);
    dirs.resize(m);
    for (int i = 0; i < m + 1; i++) {
        lcs[i].resize(n + 1, 0);
        dirs[i].resize(n, directions());
    }
    for (size_t i = 1; i < m + 1; i++) {
        for (size_t j = 1; j < n + 1; j++) {
            if (s1.at(i - 1) == s2.at(j - 1)) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                dirs[i - 1][j - 1].dirMember = dir::upleft;
            } else {
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
                dirs[i - 1][j - 1].dirMember = lcs[i - 1][j] > lcs[i][j - 1] ? dir::up : dir::left;
            }
        }
    }
    std::string substring;
    substring.reserve(std::min(m, n));
    retrieve_lcs(&substring, &s1, &dirs, m - 1, n - 1);
    solution sol;
    sol.length=lcs[m][n];
    sol.subsequence=substring;
    return sol;
}

void retrieve_lcs(std::string *str, std::string *s1, std::vector<std::vector<directions >> *dirs, size_t i, size_t j) {
//    std::cout<<"i: "<<i<<" j: "<<j<<"\n";
//    std::cout<<"Direction: "<<dirs->at(i)[j].dirMember<<"\n";

    if (dirs->at(i)[j].dirMember == dir::upleft) {
//        std::cout<<"i-1: "<<i-1<<" j-1: "<<j-1<<"\n";
//        std::cout<<"test: "<<((int)i - 1 > -1 && (int)j - 1 > -1)<<"\n";
        if ((int)i - 1 > -1 && (int)j - 1 > -1) {
//            std::cout<<"dupa"<<"\n";
            retrieve_lcs(str, s1, dirs, i - 1, j - 1);
        }
//        std::cout<<"Appending string with "<<s1->at(i)<<"\n";
        str->append(&s1->at(i), 1);

    } else {
        if (dirs->at(i)[j].dirMember == dir::left && j > 0) {
            retrieve_lcs(str, s1, dirs, i, j - 1);
        }
        else if (dirs->at(i)[j].dirMember == dir::up && i > 0) {
            retrieve_lcs(str, s1, dirs, i - 1, j);
        }
    }
}

int main() {
    std::string s1="abcbdab";
    std::string s2 = "bdcaba";
    solution sol=LCS_dynamic(s1, s2);
    std::cout<<sol.subsequence<<"\n";
    std::cout<<sol.length<<"\n";
    return 0;
}