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
// the spacial unnamed bit field of size zero can be forced to break up padding.
// padding, means: soft material that is placed inside something to make it more comfortable
// or to change its shape.
// It specifies that the next bit field begins at the beginning of its allocated unit:

struct S {
    unsigned char b1: 3;    // +3
    // starts form a new bit
    unsigned char: 0;       // +7
    unsigned char b2: 6;    // +6
    unsigned char b3: 2;    // +2
};

/// Note:
// If the specified size of the bit field is greater than the size of its type,
// the value is limited by the type: a std::uint8_t b: 1000, would be still hold
// values between 0 and 255, the extra bits become unused padding.
//
// There are no default initializer for bit field: int b:1 =0, and int b:2{0} are ill-formed
// A bit field cannot be a static data member
// There is no bit field pr-value

int main(){

}







