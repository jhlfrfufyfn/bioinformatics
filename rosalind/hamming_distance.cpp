#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

int hamming_distance(const std::string& str1, const std::string& str2) {
    int ans = 0;
    for (int index = 0; index < str1.size(); index++) {
        if (str1[index] != str2[index]) {
            ans++;
        }
    }
    return ans;
}

int main() {
    std::ifstream input("rosalind_rna.txt");
    std::ofstream output("output.txt");
    std::string str1;
    std::string str2;

    input >> str1 >> str2;
    output << hamming_distance(str1, str2);

    return 0;
}
