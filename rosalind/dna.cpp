#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

std::tuple<int, int, int, int> count_nucleotides(const std::string& file_name) {
    std::ifstream input_file(file_name);
    std::string text;
    input_file >> text;
    return {
        std::count(text.begin(), text.end(), 'A'),
        std::count(text.begin(), text.end(), 'C'),
        std::count(text.begin(), text.end(), 'G'),
        std::count(text.begin(), text.end(), 'T')
    };
}

int main() {
    auto ans = count_nucleotides("rosalind_dna.txt");
    std::cout << std::get<0>(ans) << " " << std::get<1>(ans)
              << " " << std::get<2>(ans) << " " << std::get<3>(ans);
    return 0;
}