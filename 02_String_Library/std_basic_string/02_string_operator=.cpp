#include <iostream>
#include <string>
#include <cassert>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/* std::basic_string::operator=

basic_string& operator=( const basic_string& str ); (1)

basic_string& operator=( basic_string&& str );  (2)	(since C++11)

basic_string& operator=( const CharT* s );

basic_string& operator=( CharT ch );

basic_string& operator=( std::initializer_list<CharT> ilist ); (since C++11)

*/

int main (int ac,char **av, char **lvs) {
    {
        std::string s("test 1 operator =");
        std::string p;
        p.operator=(s); /// p = s;
        cout<<s<<endl;
    }
    {
        std::string const s("test 2 operator = ");
        std::string d;
        d.operator=(s);
        cout<<d<<endl;

    }
    {
        std::string s("test 3 operator = ");
        s.operator=('=');
        cout<<s<<endl;
    }
    {
        std::string s("test 4 operator =");
        s.operator=("test by char*");
        cout<<s<<endl;
    }
    {
        std::string s("test 5 operator =");
        s.operator=({'{','+','}'});
        cout<<s<<endl;
    }
}
