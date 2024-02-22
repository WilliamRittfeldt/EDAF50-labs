#include <iostream>
#include <sstream>
#include <string>
#include "toString.h"


template <class T>
std::string toString(const T& obj) {
    std::ostringstream oss;
    oss << obj; 
    return oss.str(); 
}
