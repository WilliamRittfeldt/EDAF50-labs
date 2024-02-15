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


constexpr int maxlen{25};

Dictionary::Dictionary() : words(maxlen){
	std::ifstream inputFile("words_in.txt");
	std::string word;
    //vector<Word> words[maxlen];

	while (inputFile >> word) {
        int wordLength = word.length();
        if (wordLength <= 25) {
            words[wordLength].push_back(Word(word, computeTrigrams(word)));
            //cout << "word: " << word << " inserted into vector" << endl;
        }
    }
	inputFile.close(); //behövs detta?

}

bool Dictionary::contains(const string& word) const {

    for (const auto& w : words[word.length()]) {
        if (w.get_word() == word) {
            return true;
        }
    }
    return false; // Word not found
}

vector<string> Dictionary::get_suggestions(const std::string& word) const {
	vector<string> suggestions;
    add_trigram_suggestions(suggestions, word);
    //rank suggestions EDIT DISTANCE
    trim_suggestions(suggestions);
	return suggestions;
}

//check words with length-1 to length+1, append suggestions if >= half of trigrams match
void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const std::string& word) const{
    int wlen = word.length();
    if (wlen > maxlen) { //if word too long, discard
        return;
    }

    std::vector<std::string> trigrams = computeTrigrams(word);
    unsigned int halfTrigs = trigrams.size()/2;
    
    for (int i = wlen-1; i <= wlen+1; i++) {
        for (const Word& dict_word : words[i]){ 
            if (dict_word.get_matches(trigrams) >= halfTrigs) {
                suggestions.push_back(dict_word.get_word());
            }
        }

    }
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
    if (suggestions.size() > 5) suggestions.resize(5); 
}


int edit_distance(const std::string& p, const std::string& q) {
    int m = p.length(), n = q.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // Initialize the table
    for(int i = 0; i <= m; i++){
		dp[i][0] = i;
	} 
    for(int j = 0; j <= n; j++){
		dp[0][j] = j;
	} 

    // Compute the distances
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int cost = (p[i - 1] == q[j - 1]) ? 0 : 1;
            dp[i][j] = std::min({ dp[i - 1][j - 1] + cost, // Substitution
                                  dp[i - 1][j] + 1,       // Deletion
                                  dp[i][j - 1] + 1 });    // Insertion
        }
    }
    return dp[m][n];
}

//taken from preprocessor
std::vector<std::string> Dictionary::computeTrigrams(const std::string& word) const{
    std::vector<std::string> trigrams;
    for (size_t i = 0; i + 2 < word.size(); ++i) {
        auto trig = word.substr(i, 3);
        if (trig.size() == 3) { 
            trigrams.push_back(word.substr(i, 3));
        }
    }
    return trigrams;
}

