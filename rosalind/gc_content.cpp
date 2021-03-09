#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

double GetCGContent(const std::string& str) {
    return (std::count(str.begin(), str.end(), 'C') + std::count(str.begin(), str.end(), 'G')) / (double)str.size();
}

int main() {
    std::ifstream input("rosalind_rna.txt");
    std::ofstream output("output.txt");

    std::vector<std::pair<std::string, std::string> > name_dna;

    std::string line;
    input >> line;
    while (true) {
        name_dna.emplace_back(line, "");
        while (input >> line && line[0] != '>') {
            name_dna.back().second += line;
        }
        if (input.eof()) {
            break;
        }
    }

    int max_index = (std::max_element(name_dna.begin(), name_dna.end(),[](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
        return GetCGContent(a.second) < GetCGContent(b.second);
    }) - name_dna.begin());

    output << name_dna[max_index].first.substr(1) << "\n";
    output << std::setprecision(6) << GetCGContent(name_dna[max_index].second) * (double)100;
    return 0;
}
