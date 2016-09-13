#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::find_first_of . it is like find
/*

size_type find_first_of( const basic_string& str, size_type pos = 0 ) const;(1)
size_type find_first_of( const CharT* s, size_type pos, size_type count ) const;(2)
size_type find_first_of( const CharT* s, size_type pos = 0 ) const;(3)
size_type find_first_of( CharT ch, size_type pos = 0 ) const;(4)


Finds the first character equal to one of the characters in the given character sequence. The search considers only the interval [pos, size()). If the character is not present in the interval, npos will be returned.
1) Finds the first character equal to one of the characters in str.
2) Finds the first character equal to one of the characters in the first count characters of the character string pointed to by s. s can include null characters.
3) Finds the first character equal to one of the characters in character string pointed to by s. The length of the string is determined by the first null character.
4) Finds the first character equal to ch.

Parameters
str	-	string identifying characters to search for
pos	-	position at which to begin searching
count	-	length of character string identifying characters to search for
s	-	pointer to a character string identifying characters to search for
ch	-	character to search for

Return value
Position of the found character or npos if no such character is found.
*/

int main() {
    {
        ///size_type find_first_of( const basic_string& str, size_type pos = 0 ) const;(1)
        ///size_type find_first_of( const CharT* s, size_type pos, size_type count ) const;(2)
        ///size_type find_first_of( const CharT* s, size_type pos = 0 ) const;(3)
        ///size_type find_first_of( CharT ch, size_type pos = 0 ) const;(4)
    }
    {
        /// c plus plus reference
            // the test string
    std::string str = std::string("Hello World!");

    // strings and chars to search for
    std::string search_str = std::string("o");
    const char* search_cstr = "Good Bye!";

    std::cout << str.find_first_of(search_str) << '\n';
    std::cout << str.find_first_of(search_str, 5) << '\n';
    std::cout << str.find_first_of(search_cstr) << '\n';
    std::cout << str.find_first_of(search_cstr, 0, 4) << '\n';
    // 'x' is not in "Hello World', thus it will return std::string::npos
    std::cout << str.find_first_of('x') << '\n';
    }
}




















