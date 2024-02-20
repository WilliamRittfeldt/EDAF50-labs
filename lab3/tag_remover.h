#ifndef TAG_REMOVER_H
#define TAG_REMOVER_H

#include <iostream>
#include <string>

class TagRemover {
public:
    TagRemover(std::istream& input);
    void print(std::ostream& output);

private:
    std::string content;
    std::string removeTags(const std::string& input);
    std::string decodeSpecialChars(const std::string& input);
};

#endif // TAG_REMOVER_H
