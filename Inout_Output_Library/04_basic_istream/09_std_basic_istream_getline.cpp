/**
std::basic_istream
**/


/// 09_std::basic_istream::getline
/**

basic_istream& getline ( char_type* s, std::streamsize count );
basic_istream& getline ( char_type* s, std::streamsize count, char_type delim );

Extract character from stream until and of line or the specified delimiter delim.
    The first version is equivalent to getline (s, count, widen('\n')).

Return value : *this

**/
#include <iostream>
#include <sstream>
#include <vector>
#include <array>


int main() {
    {
        /// mine

    }
    {
        /// the site sample
        std::basic_istringstream<char> input("abc|def|hg");
        std::vector<std::array<char,4>> v;

        /// Note : the following loop terminates when std::ios_base::operator bool()
        /// on the stream returned from getline() returns false
        for ( std::array<char,4> a; input.getline(&a[0], 4, '|'); ){
            v.push_back(a);
        }

        for ( auto& a : v)
            std::cout<<&a[0]<<'\n';
    }
    {
        /// msdn.microsoft.com
    }

}












