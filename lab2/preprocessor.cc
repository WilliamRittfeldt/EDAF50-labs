#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// Function to compute trigrams for a given word
std::vector<std::string> computeTrigrams(const std::string& word) {
    std::vector<std::string> trigrams;
    for (size_t i = 0; i + 2 < word.size(); ++i) {
        auto trig = word.substr(i, 3);
        if (trig.size() == 3) { 
            trigrams.push_back(word.substr(i, 3));
        }
    }
    return trigrams;
}

int main() {
    std::ifstream inputFile("words_in.txt"); // Replace "input.txt" with your input file name
    std::ofstream outputFile("words.txt"); // The file where the output will be written

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file(s)." << std::endl;
        return 1;
    }

    std::string word;
    while (getline(inputFile, word)) {
        auto trigrams = computeTrigrams(word);
        outputFile << word << " " << trigrams.size();
        for (const auto& trigram : trigrams) {
            outputFile << " " << trigram;
        }
        outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
