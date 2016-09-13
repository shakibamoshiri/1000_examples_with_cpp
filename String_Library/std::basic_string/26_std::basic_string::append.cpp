#include <iostream>
#include <string>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::append
/*
basic_string& append( size_type count, CharT ch );

basic_string& append( const basic_string& str );

basic_string& append( const basic_string& str,
                      size_type pos,
                      size_type count ); (until C++14)

basic_string& append( const basic_string& str,
                      size_type pos,
                      size_type count = npos); (since C++14)

basic_string& append( const CharT* s,
                      size_type count ); (4)

basic_string& append( const CharT* s ); (5)

template< class InputIt >
basic_string& append( InputIt first, InputIt last ); (6)

basic_string& append( std::initializer_list<CharT> ilist ); (7)	(since C++11)


Appends additional characters to the string.
1) Appends count copies of character ch
2) Appends string str
3) Appends a substring [pos, pos+count) of str. If the requested substring lasts past the end of the string, or if count == npos, the appended substring is [pos, size()). If pos >= str.size(), std::out_of_range is thrown.
4) Appends the first count characters of character string pointed to by s. s can contain null characters.
5) Appends the null-terminated character string pointed to by s. The length of the string is determined by the first null character.
6) Appends characters in the range [first, last).
This overload has the same effect as overload (1) if InputIt is an integral type.	(until C++11)
This overload only participates in overload resolution if InputIt satisfies InputIterator.	(since C++11)
7) Appends characters in the initializer list ilist.

Parameters
count	-	number of characters to append
ch	-	character value to append
first, last	-	range of characters to append
str	-	string to append
s	-	pointer to the character string to append
ilist	-	initializer list with the characters to append
Return value
*this


*/


int main() {
    {
        /// test append ( size_type , char )
         std::basic_string<char> s;
        s.append(3,'*');
        s.append(2,'1').append(2,'2').append(2,'3');/// Because of *this
        cout<<s<<endl;

        /// test append (constant basic_string& )
        std::string t = "Hello";
        s.append(t);
        cout<<s<<endl;

        /// append ( constant basic_string&, size_type  position , size_type count ) c++14
        std::string t2 = "0123 World 456";
        s.append(t2,5,5);
        cout<<s<<endl;

        /// 4) append ( constant char* , size_type count )
        char* name = "and Shakib";
        s.append(name,10);
        cout<<s<<endl;

        /// 5) append(constant char* )
        char* saybye = " and Good-bye ";
        s.append(saybye);
        cout<<s<<endl;

        /// 6) append ( Input first, Input last ) = append range
        std::string ts ("space space");
        s.append(&ts[3],&ts[8]);
        cout<<s<<endl;

        /// 7) append (std::initializer_list<char> )
        std::initializer_list<char> i = {'A','B','C'};
        s.append(i);
        cout<<s<<endl;
    }
}


















