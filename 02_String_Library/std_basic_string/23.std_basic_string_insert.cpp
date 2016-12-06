#include <iostream>
#include <string>
#include <cassert>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::insert
/*

1. basic_string& insert( size_type index, size_type count, CharT ch );

2. basic_string& insert( size_type index, const CharT* s );

3. basic_string& insert( size_type index, const CharT* s, size_type count );

4. basic_string& insert( size_type index, const basic_string& str );

5. basic_string& insert( size_type index, const basic_string& str,
                      size_type index_str, size_type count ); (until C++14)

6. basic_string& insert( size_type index, const basic_string& str,
                      size_type index_str, size_type count = npos);(since C++14)(6)

7. iterator insert( iterator pos, CharT ch ); (until C++11)

7. iterator insert( const_iterator pos, CharT ch ); (since C++11) (7)

9. void insert( iterator pos, size_type count, CharT ch ); (until C++11)

8. iterator insert( const_iterator pos, size_type count, CharT ch ); (since C++11)

8. template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last ); (until C++11)

9. template< class InputIt >
iterator insert( const_iterator pos, InputIt first, InputIt last ); (since C++11)

9. iterator insert( const_iterator pos, std::initializer_list<CharT> ilist ); (since C++11)

Inserts characters into the string.
1) Inserts count copies of character ch at the position index
2) Inserts null-terminated character string pointed to by s at the position index.
    The length of the string is determined by the first null character (effectively calls Traits::length(s).
3) Inserts the first count characters from the character string pointed to by s at the position index. s can contain null characters.
4) Inserts string str at the position index
5) Inserts a string, obtained by str.substr(index_str, count) at the position index
6) Inserts character ch before the character pointed by pos
7) Inserts count copies of character ch before the element pointed by pos
8) Inserts characters from the range [first, last) before the element pointed by pos.
    This overload does not participate in overload resolution if InputIt does not satisfy InputIterator. (since C++11)
9) Inserts elements from initializer list ilist before the element pointed by pos
*/


int main() {
    { /// Sample of c plus plus reference
        std::string s("xmplr");

        /// insert(size_type index, size_type count, char ch)
        s.insert(0,1,'E');
        cout<<s<<endl;

        /// insert(size_type index, char* s)
        s.insert(2,"e");
        cout<<s<<endl;

        /// insert(size_type index, string const& str)
        s.insert(6,std::string("a"));
        cout<<s<<endl;

        /// insert(size_type index, string const& str, size_type index_str, size_type count)
        s.insert(0,std::string(" is an example string"),0,std::string::npos);
        /// insert(0,std::string("Hello "),0,std::string::npos); okay
        cout<<s<<endl;

        /// insert( iterator pos, char ch)
        s.insert( s.begin() + s.find_first_of('n') + 1, ':');
        cout<<s<<endl;

        /// insert ( iterator pos, size_type count, char ch)
        s.insert(s.find_first_of(':')+1, 3 , '+');
        cout<<s<<endl;

        /// insert ( iterator pos, Input first, Input last )
        {
            std::string const t("suitable");
            s.insert( std::begin(s) + s.find_last_of('+')+1, t.begin(),t.end());
            cout<<s<<endl;
        }

        /// insert ( constant-iterator, std::initializer_list<char> )
        std::initializer_list<char> period = {'.'};
        s.insert(std::begin(s) + s.find_first_of('g') + 1, period );
        cout<<s<<endl;

        std::initializer_list<char> settos = {'A','B','C','\n'}; /// '\0' not okay
        s.insert(std::begin(s) + s.find_first_of('.') + 1, settos );
        cout<<s<<endl;



    }
}


















