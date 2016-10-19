#include <iostream>
#include <string>
#include <iomanip>




using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// std::basic_string::compare
/*


int compare( const basic_string& str ) const; (1)
int compare( size_type pos1, size_type count1,
             const basic_string& str ) const; (2)	(3)
int compare( size_type pos1, size_type count1,
             const basic_string& str,
             size_type pos2, size_type count2 ) const; (until C++14)
int compare( size_type pos1, size_type count1,
             const basic_string& str,
             size_type pos2, size_type count2 = npos ) const; (since C++14)
int compare( const CharT* s ) const; (4)
int compare( size_type pos1, size_type count1,
             const CharT* s ) const; (5)
int compare( size_type pos1, size_type count1,
             const CharT* s, size_type count2 ) const; (6)

Compares two character sequences.
1) Compares this string to str. First, calculates the number of characters to compare, as if by size_type rlen = std::min(size(), str.size()). Then compares by calling Traits::compare(data(), str.data(), rlen). For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the strings are equal so far), then their sizes are compared as follows:
Condition	Result	Return value
Traits::compare(data, arg, rlen) < 0	data is less than arg	<0
Traits::compare(data, arg, rlen) == 0	size(data) < size(arg)	data is less than arg	<0
size(data) == size(arg)	data is equal to arg	​0​
size(data) > size(arg)	data is greater than arg	>0
Traits::compare(data, arg, rlen) > 0	data is greater than arg	>0
2) Compares a [pos1, pos1+count1) substring of this string to str as if by basic_string(*this, pos1, count1).compare(str)
3) Compares a [pos1, pos1+count1) substring of this string to a substring [pos2, pos2+count2) of str as if by basic_string(*this, pos1, count1).compare(basic_string(str, pos2, count2))
4) Compares this string to the null-terminated character sequence beginning at the character pointed to by s, as if by compare(basic_string(s))
5) Compares a [pos1, pos1+count1) substring of this string to the null-terminated character sequence beginning at the character pointed to by s, as if by basic_string(*this, pos, count1).compare(basic_string(s))
6) Compares a [pos1, pos1+count1) substring of this string to the first count2 characters of the character array whose first character is pointed to by s, as if by basic_string(*this, pos, count1).compare(basic_string(s, count2)). (Note: the characters from s to s+count2 may include null characters))

Parameters
str	-	other string to compare to
s	-	pointer to the character string to compare to
count1	-	number of characters of this string to compare
pos1	-	position of the first character in this string to compare
count2	-	number of characters of the given string to compare
pos2	-	position of the first character of the given string to compare


Return value
negative value if *this appears before the character sequence specified by the arguments, in lexicographical order
zero if both character sequences compare equivalent
positive value if *this appears after the character sequence specified by the arguments, in lexicographical order
*/


int main() {
    {
        /// 1) int compare ( constant basic_string& str )
        std::string s ("Hello World!");
        if(!s.compare(std::string("Hello World!")))
            cout<<"Equal";
        else
            cout<<"Not equal";
        cout<<endl;

        /// 2) int compare ( size_type position1 , size_type count1 , constant basic_string& str )
        if(!s.compare(0,5,std::string("Hello")))
            cout<<"Equal";
        else
            cout<<"Not equal";
        cout<<endl;

        /// 2) again
        if(!std::basic_string<char>("Hello World!",0,12).compare(s))
            cout<<"Equal";
        else
            cout<<"Not equal";
        /*
        Okay
        std::string("hello",1,2).compare(s);
        std::basic_string<char>("hello",1,2).compare(s);
        */
        cout<<endl;

        /// 3)  int compare( size_type pos1, size_type count1, const basic_string& str, size_type pos2, size_type count2 ) const; (until C++14)
        if(!s.compare(6,12,std::basic_string<char>("World!"),0,6))
           cout<<"Equal";
        else
            cout<<"Not equal";

        cout<<endl;

        if(!std::basic_string<char>("Hello").compare(0,6,std::basic_string<char>("Hello"),0,6))
            cout<<"Equal";
        else
            cout<<"Not equal";
        cout<<endl;
        /// 4) int compare ( const char* ) const
        if(!s.compare("Hello World!"))
            cout<<"Equal";
        else
            cout<<"Not equal";

        cout<<endl;
        /// 5) int compare ( size_type pos1, size_type count2 , const char* )
        if(!s.compare(0,12,"Hello World!"))
            cout<<"Equal";
        else
            cout<<"Not equal";

            cout<<endl;

        /// 6) int compare ( size_type pos1, size_type count1 , const char* s, size_type count2 )
        if(!s.compare(0,12,"Hello World!_",12))
            cout<<"Equal";
        else
            cout<<"Not equal";



    }
    { /// c plus plus reference
        /// Possible implementation

        template<class CharT, class Traits, class Alloc>
        int basic_string<CharT, Traits, Alloc>::compare(const std::basic_string& s) const noexcept
{
    size_type lhs_sz = size();
    size_type rhs_sz = s.size();
    int result = traits_type::compare(data(), s.data(), std::min(lhs_sz, rhs_sz));
    if (result != 0)
        return result;
    if (lhs_sz < rhs_sz)
        return -1;
    if (lhs_sz > rhs_sz)
        return 1;
    return 0;
}
    }
}



















