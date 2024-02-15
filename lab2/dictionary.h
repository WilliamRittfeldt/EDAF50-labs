#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	std::vector<std::string> computeTrigrams(const std::string& word) const;
private:
	std::vector<std::vector<Word>> words;
	int add_trigram_suggestions(std::vector<string>& suggestions, const std::string& word) const;
};

#endif
