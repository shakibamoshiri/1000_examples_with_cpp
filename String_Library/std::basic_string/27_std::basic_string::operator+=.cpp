#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::operator+=
/*


basic_string& operator+=( const basic_string& str ); (1)
basic_string& operator+=( CharT ch ); (2)
basic_string& operator+=( const CharT* s ); (3)
basic_string& operator+=( std::initializer_list<CharT> ilist ); (4)	(since C++11)

Appends additional characters to the string.
1) Appends string str
2) Appends character ch
3) Appends the null-terminated character string pointed to by s.
4) Appends characters in the initializer list ilist.

Parameters
str	-	string to append
ch	-	character value to append
s	-	pointer to a null-terminated character string to append
ilist	-	initializer list with the characters to append
Return value
*this
*/


int main() {
    {
        /// 1) basic_string& operator+= ( constant basic_string & )
        std::basic_string<char> s;
        s+="Hello";
        cout<<s<<endl;

        /// 2) basic_string& operator+= (charT ch)
        s+=' ';
        cout<<s<<endl;

        /// 3) basic_string& operator+= (constant char* )
        const char* t = "World";
        s+=t;
        cout<<s<<endl;

        /// 4) basic_string& operator+= ( std::initializer_list<char> )
        std::initializer_list<char> endpoind{'!'};
        s+=endpoind;
        cout<<s<<endl;
    }
    {
       std::string str;
       str.reserve(50); //reserves sufficient storage space to avoid memory reallocation
       std::cout << std::quoted(str) << '\n'; //empty string

       str += "This";
       std::cout << std::quoted(str) << '\n';

       str += std::string(" is ");
       std::cout << std::quoted(str) << '\n';

       str += 'a';
       std::cout << std::quoted(str) << '\n';

       str += {' ','s','t','r','i','n','g','.'};
       std::cout << std::quoted(str) << '\n';

       str += 76.85; // equivalent to str += static_cast<char>(76.85), might not be the intent
       std::cout << std::quoted(str) << '\n';

    }
}



















