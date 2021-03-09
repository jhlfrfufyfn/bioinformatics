//
// Created by Nik Kuchin on 07.03.2021.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

void PrintPermutations(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    std::cout << res << std::endl;
    std::vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }
    do {
        for(const auto& it : vec) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    } while(std::next_permutation(vec.begin(), vec.end()));
}
int main() {
    int n;
    std::cin >> n;
    PrintPermutations(n);
    return 0;
}
