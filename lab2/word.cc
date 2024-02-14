#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

//Creates a word w with the sorted trigrams t
Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {} 

//return word
string Word::get_word() const {
	return word;
}

//Returns how many of the trigrams in t that are present in this word’s trigram vector
unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int count = 0;
	//sort t
	std::sort(t.begin(), t.end());
	std::sort(trigrams.begin(), trigrams.end()); //just in case :))

	int maxIndex = std::min(t.size(),trigrams.size());

	for (int i = 0; i < maxIndex; i++) {
		if (t[i].compare(trigrams[i]) == 0) {
			count++;
		}
	}
	return count;
}