/**
std::manipulators
c**/

/// 23_std::quoted
/**
Defined in header <iomanip>
template <class CharT>
|* unspecified *| quoted ( const CharT* s, CharT delim=CharT('"'),CharT escape=CharT('\\')); since c++14
template<class CharT,class Traits,class Allocator>
|* unspecified *| quoted ( const std::basic_string<CharT,Traits,Allocator>& s,
                          CharT dllim=Chart('"'), CharT escape=CharT('\\'); since c++14
template<class CharT,class Traits,class Allocator>
|* unspecified *| quoted ( std::basic_string<CharT,Traits,Allocator>& s, /// remove const before string
                          CharT dllim=Chart('"'), CharT escape=CharT('\\'); since c++14

Allows to insertion and extraction of quoted strings, such as the one found in CVS or XML.

1 and 2)    When used in an expression out << quoted (s, delim,escape), where out
            is an output stream whit char_type equal to CharT and, for overload 2,
            traits_type equal to Traits, behaves as a FormattedOutputFunction, which
             inserts into out a sequence of character seq constructed as follow:
             ...
3)          When used in an expression in >> quoted(s, delim, escape), where in is
            an input stream with char_type equal to CharT and traits_type equal to
            Traits, extracts character form in, using std::basic_istream::operator>>
            , according to the following rules:
            a:
            b:




**/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>
#include <ctime>

int main(){
    {
        /// owner


    }
    {
        /// en.reference.com

    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
