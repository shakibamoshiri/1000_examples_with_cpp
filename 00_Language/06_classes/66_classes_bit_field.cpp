/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              * bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    bit field
    Declares a class data member with explicit size, in bits. Adjacent ( means: of an area, building, a room, etc, next to the near something
    bit filed members may be packed to share and straddle              ( means: to exist within , or include activity or group of people )
    the individual bytes
*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>

/// bit field
// the numbers of bits in a bit filed sets the limit to the range of values it can hold:
struct S {
    // three-bit unsigned fields
    // allowed values are 0..7
    unsigned int b: 3;  // b has three bits or 2^3
};

int main(){
    S s={7};
    std::cout<<s.b<<std::endl;
    ++s.b;  // unsigned overflow ( guaranteed wrap-around ) wrap-around: curving or stretching round at the side, => wrap-around sunglasses
    std::cout<<s.b<<std::endl;
}







