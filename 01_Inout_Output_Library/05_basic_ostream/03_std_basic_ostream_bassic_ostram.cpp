/**
std::basic_ostrream
**/


/// 03_std::basic_ostream::basic_ostram
/**
explicit basic_ostream ( std::basic_streambuf < charT, Traits> * sb )
protected :
    basic_ostream ( const basic_ostream& rhs) = delete; since c++11
    basic_ostream ( basic_ostream&& rhs )               since c++11

1) Construct the basic_ostream object, assigning initial values to the base class
    by calling basic_ios::init(sb).
2) The copy constructor is protected, and is deleted. Output streams are not copyable.
3) The move constructor uses basic_ios<charT, Traits>::move (rhs) to move all basic_ios
    members, except for the rdbuf(), form rhs into *this. This move constructor is
    protected : it is called by the move constructor of movable output stream classes
    std::basic_ostringstream and std::basic_ofstream, which know how to correctly move
    the associated stream buffer.
**/


#include <iostream>
#include <sstream>
#include <utility>

int main()
{
    {
        /// mine
    }

    {
        /// en.reference sample
        /// Error: copy ctor is deleted
        /* std::ostream myout ( std::cout ); */

        /// okay :share buffer with cout
        std::ostream myout(std::cout.rdbuf());

        /// ERRoR : move constructor is protected
        /* std::ostream s ( std::move (std::ostringstream() << "Hello c++ 11")); */

        /// okay : move ctor called through the derived class
       /* std::ostringstream s2(std::move(std::ostringstream() << 7.1)); /// has wrong */
        std::basic_ostringstream<char> s("hello c++");
        myout << s.str() <<std::endl;
        myout << (std::basic_o stringstream<char>("hello c++11")).str() <<std::endl;

    }

    {
        /// msdn.microsoft.com
    }

}













