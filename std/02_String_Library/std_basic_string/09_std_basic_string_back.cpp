#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::back
/*
CharT& back();  (since C++11)
const CharT& back() const;  (since C++11)

Return :
reference to the last character, equivalent to operator[](size() - 1).

*/



int main (int ac,char **av, char **lvs) {
    { /// 1 normal string
        std::string s (" Test back function()");
        char* sp = &s.back();
        cout<<*sp<<endl; /// Output -> )
        s.back() = '}';
        cout<<s<<endl; /// Output -> Test back function(}
    }
    { /// 2 constant string
        std::basic_string<char> const s ("Test back function by constant case");
        const char* sp = &s.back();
        cout<<*sp<<endl; /// Output -> e
        s.back() = '}'; /// Give us an error that assignment of read-only of location s.back()
    }
}


















