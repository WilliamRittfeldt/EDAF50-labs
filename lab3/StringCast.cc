#include <sstream>     
#include <stdexcept>   
#include <string>


template<typename T>
T string_cast(const std::string& str) {
    std::istringstream stream(str);
    T obj;
    stream >> obj; //objektets input op

    if (!stream || !stream.eof()) { //om failed eller end of line
        throw std::invalid_argument("Conversion failed");
    }
    return obj;
}