#include <iostream>
#include <string>
#include <cassert>


using std::cout;
using std::cin;
using std::endl;
using std::cerr;

/*

std::basic_string::basic_string
  C++  Strings library std::basic_string
(1)
explicit basic_string( const Allocator& alloc = Allocator() );
(until C++14)
basic_string() : basic_string( Allocator() ) {}
explicit basic_string( const Allocator& alloc );
(since C++14)
basic_string( size_type count,
              CharT ch,
              const Allocator& alloc = Allocator() );
(2)
basic_string( const basic_string& other,
              size_type pos,
              size_type count = std::basic_string::npos,
              const Allocator& alloc = Allocator() );
(3)
basic_string( const CharT* s,
              size_type count,
              const Allocator& alloc = Allocator() );
(4)
basic_string( const CharT* s,
              const Allocator& alloc = Allocator() );
(5)
template< class InputIt >
basic_string( InputIt first, InputIt last,
              const Allocator& alloc = Allocator() );
(6)
basic_string( const basic_string& other );
(7)
basic_string( const basic_string& other, const Allocator& alloc );
(7)	(since C++11)
basic_string( basic_string&& other );
(8)	(since C++11)
basic_string( basic_string&& other, const Allocator& alloc );
(8)	(since C++11)
basic_string( std::initializer_list<CharT> init,
              const Allocator& alloc = Allocator() );
(9)	(since C++11)

*/

int main (int ac,char **av, char **lvs) {
    {
    std::string s;
    assert(s.empty() && ( s.length()==0 ) && ( s.size() == 0 )   );
    }
    {
        std::string s(5,'f');
        cout<<s<<endl;
    }
    {
        std::string const other("Exemplary");
        std::string s(other, 0, other.length()-1);
        cout<<s<<endl;
    }
    {
        std::string s("C-style string", 7);
        cout<<s<<endl;
    }
    {
        std::string s("C-style\0string");
        cout<<s<<endl;
    }
    {
        char mutable_c_str[] = "another C-style string";
        std::string s(std::begin(mutable_c_str)+8, std::end(mutable_c_str)-1);
        cout<<s<<endl;
    }
    {
        std::string const other("Exemplary");
        std::string s(other);
        cout<<s<<endl;
    }
    {
        std::string s(std::string("C++ by ") + std::string("example"));
        cout<<s<<endl;
    }
    {
        std::string s({'C','-','s','t','y','l','e'});
        cout<<s<<endl;
    }

}
