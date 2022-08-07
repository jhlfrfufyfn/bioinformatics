#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> prefix_function(const string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
	cout << "Enter text:" << "\n";
	string text;
	getline(cin, text, '\n');
	
	cout << "Enter word to find: " << "\n";
	string word; 
	getline(cin, word, '\n');
	
	string temp = word + "#" + text;

	vector<int> pref = prefix_function(temp);
	
	
	for (int i = word.size(); i < temp.size(); i++) {
		if (pref[i] == word.size()) {
			cout << "Found in position " << i - 2*word.size();	
			return 0;
		}
	}
	cout << "Not found";
	return 0;
}
