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
// Multiple adjacent bit fields are usually packed together
// although this behavior is implementation-defined
struct S {
    // will usually occupy 2 ( to fill or use a space or an amount of time )

    unsigned char c1: 3, : 2, c2: 6, c3: 2, : 3;
    // c1 3 bits
    //    2 bits unused
    // c2 6 bits
    // c3 2 bits
    //    3 bits unused
    // total of used bits is almost (3+6+2)
};

int main(){
    std::cout<<sizeof(S)<<std::endl;
}







