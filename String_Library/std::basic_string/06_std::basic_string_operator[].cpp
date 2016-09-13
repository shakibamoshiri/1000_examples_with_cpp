#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::operator[]
/*
reference       operator[]( size_type pos );          (1)
const_reference operator[]( size_type pos ) const;    (2)

*/



int main (int ac,char **av, char **lvs) {
    { /* 1 */
        std::string s("Test 1 operator [] ");
        cout<<s[5]; /// output is 1
    }
    {/* 2 */
        std::basic_string<char> const s("Test 2 const operator[]");
        cout<<s[5]; /// output is 2
    }
}


















