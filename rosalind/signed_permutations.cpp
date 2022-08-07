//
// Created by Nik Kuchin on 07.03.2021.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

std::vector<std::vector<int> > genPermutations(int n) {
    std::vector<std::vector<int> > ans;

    std::vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }

    do {
        ans.push_back(vec);
    } while (std::next_permutation(vec.begin(), vec.end()));

    return ans;
}

void PrintSignedPermutations(const std::vector<std::vector<int> >& vec, int n) {
    std::ofstream output("output.txt");
    int factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial *= i;
    }
    output << (1<<n) * factorial << "\n";
    for(const auto& permutation : vec) {
        for (int mask = 0; mask < (1 << n); mask++) {
            std::vector<int> current = permutation;
            for (int j = 0; j < n; j++) {
                if (!((mask >> (n - j - 1)) & 1)) {
                    current[j] *= -1;
                }
            }
            for(const auto& it : current) {
                output << it << " ";
            }
            output << "\n";
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    PrintSignedPermutations(genPermutations(n), n);
    return 0;
}