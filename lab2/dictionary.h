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
	void add_trigram_suggestions(std::vector<string>& suggestions, const std::string& word) const;
	void trim_suggestions(std::vector<string>& suggestions) const;
	vector<string> rank_suggestions(const std::string& word, const std::vector<std::string>& suggestions) const;
	int edit_distance(const std::string& s1, const std::string& s2) const;
};

#endif
