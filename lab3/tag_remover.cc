#include "tag_remover.h"
#include <regex>
#include <sstream>
#include <fstream>

TagRemover::TagRemover(std::istream& input) {
    std::stringstream buffer;
    buffer << input.rdbuf(); // Read the entire stream into a string
    content = buffer.str();
}

std::string TagRemover::removeTags(const std::string& input) {
    std::regex tagPattern("<[^>]*>"); // Matches anything between < and >
    return std::regex_replace(input, tagPattern, "");
}

std::string TagRemover::decodeSpecialChars(const std::string& input) {
    std::string result = input;
    result = std::regex_replace(result, std::regex("&lt;"), "<");
    result = std::regex_replace(result, std::regex("&gt;"), ">");
    result = std::regex_replace(result, std::regex("&nbsp;"), " ");
    result = std::regex_replace(result, std::regex("&amp;"), "&");
    return result;
}

void TagRemover::print(std::ostream& output) {
    std::string noTags = removeTags(content);
    std::string decoded = decodeSpecialChars(noTags);
    output << decoded;
}

// int main(){
//     TagRemover tr(std::cin); // read from cin
//     tr.print(std::cout); // print on cout
// }
