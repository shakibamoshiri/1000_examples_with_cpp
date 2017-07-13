/**
std::basic_istream
**/

#include <iostream>
#include <sstream>
#include <locale>


/// 01_std::std::basic_istream::constructor
/**
explicit basic_istream( std::basic_streambuf<CharT, Traits>* sb); (1)
protected:
basic_istream( const basic_istream& rhs ) = delete; (2)	(since C++11)

protected:
basic_istream( basic_istream&& rhs );(3)	(since C++11)

1) Constructs the basic_istream object, assigning initial values to the base class by calling basic_ios::init(sb). The value of gcount() is initialized to zero.
2) The copy constructor is protected, and is deleted. Input streams are not copyable.
3) The move constructor copies the value of gcount() from rhs, sets the gcount() value of rhs to zero, and uses basic_ios<CharT, Traits>::move(rhs) to move all basic_ios members, except for the rdbuf(), from rhs into *this. This move constructor is protected: it is called by the move constructors of movable input stream classes std::basic_ifstream and std::basic_istringstream, which know how to correctly move the associated stream buffer.

Parameters
sb	-	streambuffer to use as underlying device

**/

int main() {
    {
        /// mine : did not know
        /// basic_ifstream(); (1)

        /// explicit basic_istream( std::basic_streambuf<CharT, Traits>* sb); (1)
        std::basic_istringstream<char> s1("Hello Sahkib");
        std::basic_istream<char> s2(s1.rdbuf()); /// share the buffer to input stream '>>'
        std::basic_string<char> t;
        s2 >> t;
        std::cout<<t<<std::endl;
        s2 >> t;
        std::cout<<t<<std::endl;
        s2 >> t;
        std::cout<<t<<std::endl;

        /// protected: basic_istream( const basic_istream& rhs ) = delete;    (2)	(since C++11) : by derived class
        /// protected: basic_istream( basic_istream&& rhs );                  (3)	(since C++11) : by derived class
    }
    {
        /// the site sample
        std::istringstream s1("hello");
        std::istream s2(s1.rdbuf());                        // OK: s2 shares the buffer with s1

    //    std::istream s3(std::istringstream("test"));      // ERROR: move constructor is protected
    //    std::istream s4(s2);                              // ERROR: copy constructor is deleted
        std::istringstream s5(std::istringstream("world")); // OK: move ctor called by derived class

        std::cout << s2.rdbuf() << ' ' << s5.rdbuf() << '\n';

    }
    { /// msdn.microsoft.com
    }

}












