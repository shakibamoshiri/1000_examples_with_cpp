#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::find
/*
size_type find( const basic_string& str, size_type pos = 0 ) const;(1)
size_type find( const CharT* s, size_type pos, size_type count ) const;(2)
size_type find( const CharT* s, size_type pos = 0 ) const;(3)
size_type find( CharT ch, size_type pos = 0 ) const;(4)

Finds the first substring equal to the given character sequence. Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
1) Finds the first substring equal to str.
2) Finds the first substring equal to the first count characters of the character string pointed to by s. s can include null characters.
3) Finds the first substring equal to the character string pointed to by s. The length of the string is determined by the first null character.
4) Finds the first character ch (treated as a single-character substring by the formal rules below).


*/
void print(std::string::size_type n, std::string const &s)
{
    if (n == std::string::npos) {
        std::cout << "not found\n";
    } else {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}

int main() {
    {
        ///size_type find( const basic_string& str, size_type pos = 0 ) const;(1)
        std::string s("Hello my name is Shakib");
        cout<<s.find(std::string("my"));
        cout<<s[6]<<endl;
        cout<<s[s.find(std::string("my"))];


        /// size_type find( const CharT* s, size_type pos, size_type count ) const;(2)
        cout<<endl;
        cout<<s[s.find("my",5,2)];

        /// size_type find( const CharT* s, size_type pos = 0 ) const;(3)
        cout<<endl;
        cout<<s[s.find("my")];

        ///size_type find( CharT ch, size_type pos = 0 ) const;(4)
        cout<<endl;
        cout<<s[s.find('i')];
        cout<<s.substr(s.find('i'))<<endl;

    }
    {
    std::string::size_type n;
    std::string const s = "This is a string";

    // search from beginning of string
    n = s.find("is");
    print(n, s);

    // search from position 5
    n = s.find("is", 5);
    print(n, s);

    // find a single character
    n = s.find('a');
    print(n, s);

    // find a single character
    n = s.find('q');
    print(n, s);
    }
}




















