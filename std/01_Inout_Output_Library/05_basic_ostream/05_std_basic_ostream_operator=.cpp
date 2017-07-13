/**
std::basic_ostrream
**/


/// 05_std::basic_ostream::operator=
/**
protected :
    basic_ostream& operator=( const basic_ostream& rhs ) = delete;
    basic_ostream& operator=( basic_ostream& rhs );

1)  The copy assignment is protected, and is deleted, output stream are not
    CopyAssignable.

2)  The move assignment operator exchanges all date members of the base class
    , except for rdbuf(), with 'rhs', as if by calling swap(*rhs). This move
    assignment operator is protected : it is only called by the move assignment
    operator of the derived movable output stream classes std::ofstream and
    std::ostringstream which know how to correctly move-assign the associated
    streambuffers.


**/


#include <iostream>
#include <sstream>
#include <utility>

int main()
{
    {

    }

    {
    std::ostringstream s;
//  std::cout = s;                             // ERROR: copy assignment operator is deleted
//  std::cout = std::move(s);                  // ERROR: move assignment operator is protected
    s = std::move(std::ostringstream() << 42); // OK, moved through derived
    std::cout << s.str() << '\n';

    }

    {
        /// msdn.microsoft.com
    }

}













