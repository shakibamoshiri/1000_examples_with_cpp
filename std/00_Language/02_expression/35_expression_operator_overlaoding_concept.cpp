/**

/// Expression
/// operator overloading

Overloaded operator are functions with special function mane.

operator op                         overloaded operator
operator type                       user-defined conversion function
operator new                        allocation function
operator new[]                      allocation function of array
operator delete                     deallocation function
operator delete[]                   deallocation function of array
operator"" suffix-identifier        user-defined literal since c++11

expression      member function     non-member function
@a          a.operator@()           operator@(a)
a@b         a.operator@(b)          operator(a,b)
a=b         a.operator=(b)          -
a[b]        a.operator[](b)         -
a->         a.operator->()          -
a@          a.operator@(0)          operator(a,0)

**/
#include <iostream>
#include <string>
#include <array>
/// user defined
//#include "temp.h"

int main(){
    std::string str = "this is a string";
    operator<<(std::cout,str);                              /// same as std::cout<<str;
    std::cout<<std::endl;
    str.operator+=(" and this is an operator overloading\n");    /// same as str+="and this is an operator overloading"

    operator<<(operator<<(std::cout,str),'\n');

    /// okay
    operator<<(std::cout, "hello\n");
    /// wrong
    std::cout.operator<<("\nhello\n");

}













