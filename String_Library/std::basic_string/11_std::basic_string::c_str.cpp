#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::c_str
/*
const CharT* c_str() const;

Return value
Pointer to the underlying character storage.
data()[i] == operator[](i) for every i in [0, size()).	(until C++11)
data() + i == &operator[](i) for every i in [0, size()].	(since C++11)

*/



int main (int ac,char **av, char **lvs) {
    { /// Test one : using normal
        std::string s("Test c_str function");
        const char* sp = s.c_str();
        cout<<sp<<endl;
        cout<<*sp<<endl;
        cout<<sp[0]<<endl;
        cout<<s.c_str()[s.size()-1]<<endl;
    }
}


















