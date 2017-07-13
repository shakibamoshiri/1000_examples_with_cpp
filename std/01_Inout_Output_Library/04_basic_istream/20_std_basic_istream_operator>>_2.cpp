/**
std::basic_istream
**/


/// 20_std::basic_istream::operator>>
/**

template< class CharT, class Traits >
basic_istream<CharT,Traits>& operator>>( basic_istream<CharT,Traits>& st, CharT& ch );
template< class Traits >
basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& st, signed char& ch );
template< class Traits >
basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& st, unsigned char& ch );        (1)

template< class CharT, class Traits>
basic_istream<CharT,Traits>& operator>>( basic_istream<CharT,Traits>& st, CharT* s );
template< class Traits >
basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& st, signed char* s );
template< class Traits >
basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& st, unsigned char* s );     (2)

template< class CharT, class Traits, class T >
basic_istream<CharT,Traits>& operator>>( basic_istream<CharT,Traits>&& st, T& value ); (3) since c++11

1. Behaves as an FormattedInputFunction. After constructing and checking the sentry object
    , which may skip leading whitespace, extracts a character and stores it to ch. If no _
    characters is available, sets failbit ( in addition to eofbit that is set as required
    of a FormattedInputFunction).
2. Behaves as an FormattedInputFunction. After constructing and checking the sentry object,
    which may skip leading whitespace, extracts successive characters and stores them at _
    successive location of a character array whose first element is pointed to by s. The _
    extraction strops if one of the following condition are met :
    -
    -
    -
3. Calls the appropriate extraction operator, given an rvalue reference to an input stream
    object ( equivalent to st >> value )

Return value : st

**/
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    {
        /// mine

    }
    {
        /// the site sample
        std::basic_string<char> input ("N greetings");
        std::basic_istringstream<char> stream(input);
        char c;
        const int MAX(6);
        char cstr[MAX];

        stream >> c >> std::setw(MAX) >> cstr;
        std::cout<<" c : "<< c
                 <<"\n cstr : "<< cstr << std::endl;

        double f;
        std::basic_istringstream<char>("1.23345899077") >> f;
        std::cout<<std::cout.precision(9) <<" f : "<<f<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













