/**
std::basic_istream
**/

#include <iostream>
#include <sstream>
#include <locale>


/// 03_std::basic_istream::operator=
/**
1. protected : basic_istram& operator=( const basic_istram& rhs ) = delete;
2. protected : basic_istram& operator=( const basic_istram& rhs );

1. The copy assignment operator is protected and is deleted. Input streams are not CopyAssignable.
2. The move assignment operator exchanges the gcount() values and all data members of the base class,
    except for rdbuf() with 'rbs', as if by calling swap ( * rhs). This move assignment operator is
    protected : it is only called by the move assignment operator of the derived movable input stream.
Class std::basic_isringstream and std::ifstream, which know how to correctly move-assign the
    associated streambuffers.

Parameters :
    rhs : the basic_istream object from which ot assign to *this.

**/


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::basic_istringstream<char> s1;
        s1 = std::basic_istringstream<char>("Test operator= in basic_istram");

        std::cout<<s1.str()<<std::endl;

        /// wrong initializing | operator=(basic_istream&& __rhs)
        /// std::cin = std::basic_istringstream<char>("Test operator= in basic_istram");
    }
    {
        /// msdn.microsoft.com
    }

}












