#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::find
/*
/ size_type rfind( const basic_string& str, size_type pos = npos ) const;(1)
/ size_type rfind( const CharT* s, size_type pos, size_type count ) const;(2)
/ size_type rfind( const CharT* s, size_type pos = npos ) const;(3)
/ size_type rfind( CharT ch, size_type pos = npos ) const;(4)

Finds the last substring equal to the given character sequence. Search begins at pos, i.e.
the found substring must not begin in a position following pos.
If npos or any value not smaller than size() is passed as pos, whole string will be searched.

1) Finds the last substring equal to str (equality is checked by calling Traits::eq)
2) Finds the last substring equal to the first count characters of the character string pointed to by s. s can include null characters. Equivalent to rfind(std::basic_string(s, count), pos)
3) Finds the last substring equal to the character string pointed to by s. The length of the string is determined by the first null character. Equivalent to rfind(std::basic_string(s), pos)
4) Finds the last character ch. Equivalent to rfind(std::basic_string(1,c),pos)


Parameters
str	-	string to search for
pos	-	position at which to begin searching
count	-	length of substring to search for
s	-	pointer to a character string to seach for
ch	-	character to search for
Return value
Position of the first character of the found substring or npos if no such substring is found. Note that this is an offset from the start of the string, not the end.
If size() is zero, npos is always returned.
If searching for an empty string (str.size(), count, or strlen(s) is zero) returns pos (the empty string is found immediately) unless pos == npos, in which case returns size().
*/
        void print(std::string::size_type n, std::string const &s)
        {
            if (n == std::string::npos) {
                std::cout << "not found\n";
            } else {
                std::cout << "found: \"" << s.substr(n) << "\" at " << n << '\n';
            }
        }
int main() {
    {
        /// size_type rfind( const basic_string& str, size_type pos = npos ) const;(1)
        std::string s ("am is are AM IS ARE Am Is Are am 2 is 2 are 2 AM 2 IS 2 ARE 2 Am 2 Is 2 Are 2");
        cout<<s<<endl;
        cout<<s.substr(s.rfind(std::string("is")))<<endl;
        cout<<s.substr(s.rfind(std::string("IS")))<<endl;;
        cout<<s.substr(s.rfind(std::string("Is")))<<endl;;


        /// size_type rfind( const CharT* s, size_type pos, size_type count ) const;(2)
        /// size_type rfind( const CharT* s, size_type pos = npos ) const;(3)
        /// size_type rfind( CharT ch, size_type pos = npos ) const;(4)
        cout<<endl;
        cout<<s<<endl;
        cout<<s.substr(s.rfind('i'))<<endl;
        cout<<s.substr(s.rfind('I'))<<endl;
        cout<<s.substr(s.rfind('A'))<<endl;
    }
    {
        /// c plus plus reference

            std::string::size_type n;
            std::string const s = "This is a string";

            // search backwards from end of string
            n = s.rfind("is");
            print(n, s);
            // search backwards from position 4
            n = s.rfind("is", 4);
            print(n, s);
            // find a single character
            n = s.rfind('s');
            print(n, s);
            // find a single character
            n = s.rfind('q');
            print(n, s);
    }
}




















