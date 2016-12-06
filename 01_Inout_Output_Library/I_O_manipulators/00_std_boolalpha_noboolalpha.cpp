/**
std::manipulators
c**/

/// 00_std::manipulators
/**
Defined in header <ios>
std::ios_base& boolalpha ( std::ios_base& str);
std::ios_base& noboolalpha ( std::ios_base& str);

1)  Enable the poolalpha flag in the stream str as if by calling str.setf
    ( std::ios_base::boolalpha)
2)  Disable the boolalpha flag in the stream str as if by calling str.unset
    ( std::ios_base::boolalpha)
std::boolalpha is an I/O manipulator, so it may be called with an expression
such as out << std::boolalpha for any out of type std::basic_ostream or with
an-expression such as in >> std::boolalpha for any in of typedef::basic_istream.

**/
#include <iostream>
#include <sstream>
#include <locale>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        /// boolalpha output:
        std::cout << std::boolalpha << "boolalpha true: "<<true <<std::endl
                  << "boolalpha false: "<<false<<std::endl;
        std::cout<<std::noboolalpha <<"nopoolalpha true: "<<true<<std::endl
                 <<"noboolalpha false: "<<false <<std::endl;

        /// boolalpha parse:
        bool b1,b2;
        std::istringstream is("true false");
        is >> std::boolalpha >> b1 >> b2;
        std::cout<<"is.str(): "<<is.str() << std::endl
                 <<"boolalpha parse: "<<b1<<' '<<b2;
        is.str("1 0");
        is >> std::noboolalpha >> b1 >> b2;
        std::cout<<"is.str(): "<<is.str() << std::endl
                 <<"boolalpha parse: "<<b1<<' '<<b2;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
