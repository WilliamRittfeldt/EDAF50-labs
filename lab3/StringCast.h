#ifndef STRINGCAST_H
#define STRINGCAST_H

#include <sstream>     
#include <stdexcept>   
#include <string>


template<typename T>
T string_cast(const std::string& str);

#endif