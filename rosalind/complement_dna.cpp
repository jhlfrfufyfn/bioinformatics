#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

void reverse_complement(std::string* str) {
    reverse(str->begin(), str->end());
    for(auto& it: *str){
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
}

int main() {
    std::ifstream input("rosalind_rna.txt");
    std::ofstream output("output.txt");
    std::string str;

    input >> str;
    reverse_complement(&str);
    output << str;

    return 0;
}
