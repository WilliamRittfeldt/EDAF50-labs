#include <iostream>
#include "date.h"
#include "toString.h"
#include <sstream>


template <typename T>
std::string toString(T& t){
    std::ostringstream os;
    os << t;
    return os.str();
}

int main() {
    double d = 1.234;
    Date today(22, 2, 2024); // Using today's date as an example

    std::string sd = toString(d);
    std::string st = toString(today);

    std::cout << "Double to string: " << sd << std::endl;
    std::cout << "Date to string: " << st << std::endl;

    return 0;
}
