#include <iostream>
#include <string>
#include <vector>

// preprocessing for strong good suffix rule
void preprocess_strong_suffix(std::vector<int> &shift, std::vector<int> &bpos,
                              const std::string &pat, int pattern_size) {
    int i = pattern_size, j = pattern_size + 1;
    bpos[i] = j;

    while (i > 0) {
        /*if character at position i-1 is not equivalent to
          character at j-1, then continue searching to right
          of the pattern for border */
        while (j <= pattern_size && pat[i - 1] != pat[j - 1]) {
            /* the character preceding the occurrence of t in 
               pattern P is different than the mismatching character in P, 
               we stop skipping the occurrences and shift the pattern
               from i to j */
            if (shift[j] == 0)
                shift[j] = j - i;

            //Update the position of next border 
            j = bpos[j];
        }
        /* p[i-1] matched with p[j-1], border is found.
           store the  beginning position of border */
        i--;
        j--;
        bpos[i] = j;
    }
}

//Preprocessing for case 2
void preprocess_case2(std::vector<int> &shift, std::vector<int> &bpos,
                      const std::string &pat, int m) {
    int j = bpos[0];
    for (int i = 0; i <= m; i++) {
        /* set the border position of the first character of the pattern
           to all indices in array shift having shift[i] = 0 */
        if (shift[i] == 0)
            shift[i] = j;

        /* suffix becomes shorter than bpos[0], use the position of 
           next widest border as value of j */
        if (i == j)
            j = bpos[j];
    }
}

/*Search for a pattern in given text using
  Boyer Moore algorithm with Good suffix rule */
void search(const std::string &text, const std::string &pattern) {
    size_t pattern_size = pattern.size();
    size_t text_size = text.size();

    // pattern_shift is shift of the pattern with respect to text
    int pattern_shift = 0;

    std::vector<int> bpos(pattern_size + 1);
    std::vector<int> shift(pattern_size + 1);

    //initialize all occurrence of shift to 0
    for (int i = 0; i < pattern_size + 1; i++) {
        shift[i] = 0;
    }

    //do preprocessing
    preprocess_strong_suffix(shift, bpos, pattern, pattern_size);
    preprocess_case2(shift, bpos, pattern, pattern_size);

    while (pattern_shift <= text_size - pattern_size) {''
        int j = (int) pattern_size - 1;
        /* Keep reducing index j of pattern while characters of
             pattern and text are matching at this shift pattern_shift*/
        while (j >= 0 && pattern[j] == text[pattern_shift + j]) {
            j--;
        }
        /* If the pattern is present at the current shift, then index j
             will become -1 after the above loop */
        if (j < 0) {
            std::cout << "паттерн найден в позиции " << pattern_shift << "\n";
            pattern_shift += shift[0];
        } else
            /*pattern[i] != pattern[pattern_shift+j] so shift the pattern
              shift[j+1] times  */
            pattern_shift += shift[j + 1];
    }

}

int main() {
    std::string text = "ABAAAABAACD";
    std::string pattern = "ABA";
    search(text, pattern);
    return 0;
}