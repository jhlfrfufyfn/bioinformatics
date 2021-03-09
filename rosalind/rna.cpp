#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

void transcribe(std::string* str) {
    std::replace(str->begin(),str->end(), 'T', 'U');
}

int main() {
    std::ifstream input("rosalind_rna.txt");
    std::ofstream output("output.txt");
    std::string str;

    input >> str;
    transcribe(&str);
    output << str;

    return 0;
}
