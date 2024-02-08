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
#include <fstream>
#include <iostream>

std::unordered_set<std::string> words;

Dictionary::Dictionary() {
	std::ifstream inputFile("words_in.txt");
	std::string word;

	while (inputFile >> word) {
        words.insert(word);
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
