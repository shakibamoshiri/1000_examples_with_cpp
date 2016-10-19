#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::front
/*
CharT& front();  (since C++11)
const CharT& front() const;  (since C++11)

Returns reference to the first character in the string. The behavior is undefined if empty() == true.

Parameters  (none)
Return value
reference to the first character, equivalent to operator[](0).


*/



int main (int ac,char **av, char **lvs) {
    {
    std::basic_string<char> s("Test front function()");
    char& sp = s.front();
    cout<<sp<<endl; /// Output is T
    /// Or
    char* sp2 = &s.front();
    cout<<*sp2<<endl; /// Output is T
    }
    { /* for constant 2 */
        std::string const s("constant sample front function()");
        const char* sp = &s.front();
        cout<<*sp<<endl; /// output is c
        /// Or
        const char& sp2 = s.front();
        cout<<sp2<<endl; /// output is c
    }
    /// charge the value
    {
        std::string s("front for the change one character");
        s.front() = 'F';
        cout<<s<<endl;


    }
    {/// Cannot change the constant value
        std::basic_string<char> const s ("Test constant, that does can change it?");
        s.front() = 'F'; /// Give us an error : assignment of read-only location s....
        cout<<s<<endl;
    }
}


















