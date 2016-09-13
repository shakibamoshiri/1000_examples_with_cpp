#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::compare
/*

basic_string& replace( size_type pos, size_type count,
                       const basic_string& str ); (1)
basic_string& replace( const_iterator first, const_iterator last,
                       const basic_string& str ); (1)	(2)
basic_string& replace( size_type pos, size_type count,
                       const basic_string& str,
                       size_type pos2, size_type count2 ); (until C++14)

basic_string& replace( size_type pos, size_type count,
                       const basic_string& str,
                       size_type pos2, size_type count2 = npos );(since C++14)

template< class InputIt >
basic_string& replace( const_iterator first, const_iterator last,
                       InputIt first2, InputIt last2 ); (3)

basic_string& replace( size_type pos, size_type count,
                       const CharT* cstr, size_type count2 ); (4)

basic_string& replace( const_iterator first, const_iterator last,
                       const CharT* cstr, size_type count2 ); (4)

basic_string& replace( size_type pos, size_type count,
                       const CharT* cstr ); (5)

basic_string& replace( const_iterator first, const_iterator last,
                       const CharT* cstr ); (5)

basic_string& replace( size_type pos, size_type count,
                       size_type count2, CharT ch ); (6)

basic_string& replace( const_iterator first, const_iterator last,
                       size_type count2, CharT ch ); (6)

basic_string& replace( const_iterator first, const_iterator last,
                       std::initializer_list<CharT> ilist ); (7)	(since C++11)


Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new string.
The new string can be one of:
1) string str;
2) substring [pos2, pos2 + count2) of str
3) characters in the range [first2, last2)
This overload has the same effect as overload (6) if InputIt is an integral type.	(until C++11)
This overload only participates in overload resolution if InputIt satisfies InputIterator.	(since C++11)
4) first count2 characters of the character string pointed to by cstr;
5) null-terminated character string pointed to by cstr;
6) count2 copies of character ch;
7) characters in the initializer list ilist;


Parameters
pos	-	start of the substring that is going to be replaced
count	-	length of the substring that is going to be replaced
first, last	-	range of characters that is going to be replaced
str	-	string to use for replacement
pos2	-	start of the substring to replace with
count2	-	number of characters to replace with
cstr	-	pointer to the character string to use for replacement
ch	-	character value to use for replacement
first2, last2	-	range of characters to use for replacement
ilist	-	initializer list with the characters to use for replacement


Return value
*this


Exceptions
std::out_of_range if pos > length() or pos2 > str.length()
std::length_error if the resulting string will exceed maximum possible string length (std::string::npos - 1)
In any case, if an exception is thrown for any reason, this function has no effect (strong exception guarantee). (since C++11)
*/


int main() {
    {
        /// 1) basic_string& replace ( size_type pos, size_type count1, constant basic_string& str )
        std::string s ("me name is shakiba");
        cout<<s<<endl;
        s.replace(0,2,std::string("My"));
        cout<<s<<endl;

        /// 1) basic_string& replace ( constant_iterator first, constant_iterator last, std::basic_string& )
        cout<<endl;
        cout<<s<<endl;
        s.replace(s.begin()+3, s.begin()+7,std::string("NAME"));
        cout<<s<<endl;

        /// 2) basic_string& replace ( size_type pos1, size_type count1, std::basic_string& , size_type pos2 , size_type count2 )
        cout<<endl;
        cout<<s<<endl;
        s.replace(11,1,std::basic_string<char>("S----A"),0,1);
        cout<<s<<endl; /// 's' to 'S'

        /// 3) (constant_iterator first, constant_iterator last, Input first, Input last )
        cout<<endl;
        cout<<s<<endl;
        std::string was = "was";
        s.replace(s.begin()+8,s.end()-8,was.begin(),was.end());
        cout<<s<<endl;

        /// 4) basic_string& replace ( size_type pos, size_type count2, constant char*, size_type count2 )
        /// or
        /// 4) basic_string& replace (constant_iterator first, constant_iterator last , constant char*, size_type count2 )

        cout<<endl;
        cout<<s<<endl;
        s.replace(8,3,"is",2);
        cout<<s<<endl;
        s.replace(std::begin(s)+8,std::end(s)-8,"was",3);
        cout<<s<<endl;

        /// 5) basic_string& replace ( size_type pos, size_type count2, constant char* )
        /// or
        /// 5) basic_string& replace ( constant_iterator first, constant_iterator_last , constant char* )
        cout<<endl;
        cout<<s<<endl;
        s.replace(3,4,"name");
        cout<<s<<endl;
        s.replace(s.begin()+3,s.begin()+7,"NamE");
        cout<<s<<endl;

        /// 6) basic_string& replace ( size_type pos, size_type count2 , size_type count2 , charT ch )
        /// or
        /// 6) basic_string& replace ( constant_iterator first, constant_iterator last , size_type count2 , charT ch )
        cout<<endl;
        cout<<s<<endl;
        s.replace(13,19,6,'-');
        cout<<s<<endl;
        s.replace(s.begin()+13,s.end(),6,'+');
        cout<<s<<endl;

        /// 7) basic_string& replace ( constant_iterator first, constant_iterator last, std::initializer_list<char> list )
        cout<<endl;
        cout<<s<<endl;
        std::initializer_list<char> dot{'.'};
        s.replace(s.end()-1,s.end(),dot);
        cout<<s<<endl;

    }
    {
    std::string str("The quick brown fox jumps over the lazy dog.");

    str.replace(10, 5, "red"); // (4)

    str.replace(str.begin(), str.begin() + 3, 1, 'A'); // (5)

    std::cout << str << '\n';
}
}




















