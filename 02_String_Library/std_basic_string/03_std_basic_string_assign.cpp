#include <iostream>
#include <string>
#include <cassert>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/// Equivalent to constructor string
/* std::basic_string::assign

basic_string& assign( size_type count, CharT ch ); (1)
basic_string& assign( const basic_string& str ); (2)
basic_string& assign( const basic_string& str,
                      size_type pos,
                      size_type count ); (until C++14) (3)
basic_string& assign( const basic_string& str,
                      size_type pos,
                      size_type count = npos); (since C++14)
basic_string& assign( basic_string&& str ); (4)	(since C++11)
basic_string& assign( const CharT* s,
                      size_type count ); (5)
basic_string& assign( const CharT* s ); (6)
template< class InputIt >
basic_string& assign( InputIt first, InputIt last ); (7)
basic_string& assign( std::initializer_list<CharT> ilist ); (8)	(since C++11)
*/

int main (int ac,char **av, char **lvs) {
    {/* 1 */
        std::basic_string<char> s("test assign function");
        //std::string s("test assign function");
        s.assign(10,'=');
        cout<<s<<endl;
        s.assign(3,'-').assign(3,'+');
        cout<<s<<endl;
    }
    {/* 2 */
        std::basic_string<char> const s("test 2 assign function");
        std::string d;
        d.assign(s,5,s.size()-1);
        cout<<d<<endl;
    }
    {/* 3 */
        typedef std::basic_string<char> mystr;
        mystr s("test 3 assign function");
        mystr d;
        d.assign(s,5,s.size()-1);
        cout<<d<<endl;
    }
    {/* 4 */
        typedef std::basic_string<char> k5str;
        k5str s("test 4 assign function");
        s.assign(k5str("assign by itself"));
        cout<<s<<endl;
    }
    {/* 5 */
        std::string s__s("Test 5 assign function");
        s__s.assign("char* in test 5",7);
        cout<<s__s<<endl;
    }
    {/* 6 */
        std::string s("Test 6 assign function");
        /// basic_string& assign ( const CharT* s);
        s.assign("initialize by char*");
        cout<<s<<endl;
    }
    {/* 7 */
        std::string s("Test 7 assign function");
        /// template < class InputIT>
        /// basic_string& assign( InputIt first, InputIt last);
        std::string d = "For test number 7";
        // s.assign(d.begin(),d.end()); Okay
        s.assign(std::begin(d),std::end(d));
        cout<<s<<endl;

    }
    {/* 8 */
        /// basic_string& assign ( std::initializer_list<CharT> ilist); { }
        std::string s({'a','b','c','d','e','m'});
        cout<<s<<endl;
        s.assign({'A','B','C','D','E','M'});
        cout<<s<<endl;

    }
}


















