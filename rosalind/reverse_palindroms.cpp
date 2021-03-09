//
// Created by Nik Kuchin on 07.03.2021.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool CheckString(const std::string& s) {
    std::string complement = s;
    for (auto& it : complement) {
        if (it == 'A') {
            it = 'T';
        }
        else if (it == 'T') {
            it = 'A';
        }
        else if (it == 'C') {
            it = 'G';
        }
        else if (it == 'G') {
            it = 'C';
        }
    }
    std::reverse(complement.begin(), complement.end());
    return s == complement;
}

void Solve(const std::string& line) {
    int n = line.size();
    for (int start = 0; start < n; start++) {
        std::string s;
        for (int curr = start; curr < n; curr++) {
            s.push_back(line[curr]);
            if (s.size() >= 4 && s.size() <= 12) {
                if (CheckString(s)) {
                    std::cout << start + 1 << "\t" << s.size() << "\n";
                }
            }
            else if (s.size() > 12) {
                break;
            }
        }
    }
}

int main() {
    std::string line;
    std::cin >> line;
    std::cin >> line;

    Solve(line);
    return 0;
}