#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::find_first_not_of
/*
size_type find_first_not_of( const basic_string& str, size_type pos = 0 ) const;(1)
size_type find_first_not_of( const CharT* s, size_type pos, size_type count ) const;(2)
size_type find_first_not_of( const CharT* s, size_type pos = 0 ) const;(3)
size_type find_first_not_of( CharT ch, size_type pos = 0 ) const;(4)


Finds the first character equal to none of the characters in the given character sequence. The search considers only the interval [pos, size()). If the character is not present in the interval, npos will be returned.
1) Finds the first character equal to none of characters in str.
2) Finds the first character equal to none of characters in the first count characters of the character string pointed to by s. s can include null characters.
3) Finds the first character equal to none of characters in character string pointed to by s. The length of the string is determined by the first null character.
4) Finds the first character not equal to ch.


Parameters
str	-	string identifying characters to search for
pos	-	position for the seach to start from
count	-	length of character string identifying characters to search for
s	-	pointer to a character string identifying characters to search for
ch	-	character identifying characters to search for


Return value
Position of the found character or npos if no such character is found.
*/

int main() {
    {
        /// size_type find_first_not_of( const basic_string& str, size_type pos = 0 ) const;(1)
        std::string s ("a b d c d  * c ");
        cout<<s<<endl;
        auto f = s.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
        if(f!= std::string::npos)
            cout<<s[f]<<"found in "<<f<<endl;
        s.at(11) = '+';
        cout<<s<<endl;



        /// size_type find_first_not_of( const CharT* s, size_type pos, size_type count ) const;(2)
        /// size_type find_first_not_of( const CharT* s, size_type pos = 0 ) const;(3)
        /// size_type find_first_not_of( CharT ch, size_type pos = 0 ) const;(4)


    }
    {
            std::string to_search = "Some data with %MACROS to substitute";

    std::cout << "Before: " << to_search << '\n';

    auto pos = std::string::npos;
    while ((pos = to_search.find('%')) != std::string::npos) {
        // Permit uppercase letters, lowercase letters and numbers in macro names
        const auto after = to_search.find_first_not_of("ABCDEFGHIJKLMOPQRSTUVWXYZabcdefghijklmopqrstuvwxyz0123456789", pos + 1);

        // Now to_search[pos] == '%' and to_search[after] == ' ' (after the 'S')

        if(after != std::string::npos)
            to_search.replace(pos, after - pos, "some very nice macros");
    }

    std::cout << "After: " << to_search << '\n';
    }
}





















