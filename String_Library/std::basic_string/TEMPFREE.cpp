#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::hash
/*
std::hash (std::string, std::wstring, std::u16string, std::u32string)
C++  Strings library std::basic_string

Defined in header <string>
template<> struct hash<std::string>;
template<> struct hash<std::wstring>;
template<> struct hash<std::u16string>;
template<> struct hash<std::u32string>;
(since C++11)

template <class T> struct hash;
*/

int main() {
    {
        std::string s("Shakiba moshiri");
        std::hash<std::string> hs;
        cout<<hs(s)<<endl;

        char* name = "Shakiba moshiri";
        std::hash<char*> hname;
        cout<<hname(name)<<endl;
    }
}





















