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
    suggestions = rank_suggestions(word, suggestions);
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

vector<string> Dictionary::rank_suggestions(const std::string& word, const std::vector<std::string>& suggestions) const {
    vector<std::pair<string, int>> rankedSuggestions;
    for (const auto& s : suggestions) {
        int distance = edit_distance(word, s);
        rankedSuggestions.push_back(std::make_pair(s, distance));
    }

    //sort by distance with for loop
    for (int i = 0; i < rankedSuggestions.size(); i++) {
        for (int j = i+1; j < int(rankedSuggestions.size()); j++) {
            if (rankedSuggestions[i].second > rankedSuggestions[j].second) {
                std::swap(rankedSuggestions[i], rankedSuggestions[j]);
            }
        }
    }

    vector<string> ranked;

    for (const auto& pair : rankedSuggestions) {
        ranked.push_back(pair.first);
    }

    return ranked;

}


int Dictionary::edit_distance(const std::string& s1, const std::string& s2) const{
    int m = s1.length(), n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            int substitution = dp[i - 1][j - 1] + cost;
            int deletion = dp[i - 1][j] + 1;
            int insertion = dp[i][j - 1] + 1;
            dp[i][j] = std::min(substitution, std::min(deletion, insertion));
            
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

