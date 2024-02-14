#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using std::string;
using std::vector;
using std::cout;
using std::endl;
#include <fstream>
#include <iostream>

std::unordered_set<std::string> words;

Dictionary::Dictionary() {
	std::ifstream inputFile("words_in.txt");
	std::string word;

	while (inputFile >> word) {
        words.insert(word);
		//cout << "word: " << word << " inserted." << endl;
    }
	inputFile.close(); //behövs detta?

}

bool Dictionary::contains(const string& word) const {
	if (words.find(word) != words.end()) {
		return true;
	} 
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}


int edit_distance(const std::string& s1, const std::string& s2) {
    int m = s1.length(), n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // Initialize the table
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    // Compute the distances
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = std::min({ dp[i - 1][j - 1] + cost, // Substitution
                                  dp[i - 1][j] + 1,       // Deletion
                                  dp[i][j - 1] + 1 });    // Insertion
        }
    }
    return dp[m][n];
}

