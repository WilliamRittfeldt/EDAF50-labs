#include "date.h"
#include "StringCast.h"

using std::invalid_argument;
using std::cout;
using std::endl;


int main() {
    try {
           int i = string_cast<int>("123");
           double d = string_cast<double>("12.34");
           Date date = string_cast<Date>("2015-01-10");
   } catch (std::invalid_argument& e) {
           cout << "Error: " << e.what() << endl;
}
}
