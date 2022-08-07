//
// Created by Nik Kuchin on 08.03.2021.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>

void PrintMap(const std::unordered_map<char, double>& w) {
    for (const auto& it : w) {
        std::cout << it.first << " : " << it.second << "\n";
    }
}

void InitWeights(std::unordered_map<char, double>& weight) {
    std::ifstream in("rosalind_rna.txt");
    char ch;
    while(in >> ch) {
        double d;
        in >> d;
        weight[ch] = d;
    }
}

double Solve(const std::string& s, const std::unordered_map<char,double>& weight) {
    double ans = 0.;
    for (const auto& ch : s) {
        ans += (double)weight.at(ch);
    }
    return ans;
}

int main() {
    std::unordered_map<char,double> weight;
    InitWeights(weight);
    PrintMap(weight);
    std::string s;
    std::cin >> s;

    std::cout << std::setprecision(9) << Solve(s, weight);
    return 0;
}