#include <iostream>
#include <string>
#include <algorithm>

void solve(const std::string& text, const std::string& word) {
    for (int i = 0; i < text.size(); i++) {
        bool equals = true;
        for(int j = i + 1; j < i + word.size(); j++) {
            if (j >= text.size()) {
                equals = false;
                break;
            }
            if (text[j] != word[j - i]) {
                equals = false;
            }
        }
        if(equals) {
            std::cout << i + 1 << " ";
        }
    }

}

int main() {
    std::string text;
    std::cin >> text;

    std::string word;
    std::cin >> word;

    solve(text, word);

    return 0;
}