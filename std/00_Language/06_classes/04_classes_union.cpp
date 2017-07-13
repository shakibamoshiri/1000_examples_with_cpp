/*
Classes
    - class declaration
    * union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
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
    union declaration
    A union is a special class type that can hold only one of its
    non-static data member at a time. The class specifier for a union
    declaration is similar to class or struct declaration
    union attribute class-head-name { member-specification};
    The union is only as big as necessary to hold it largest data member.
    The other data member are allocated in the same bytes as part of largest
    member.


*/

#include <iostream>
#include <string>


union S {
    int32_t n;      // occupies 4 bytes
    uint16_t s[2];  // occupies 4 bytes
    uint8_t c;      // occupies 1 byte
};                  // the whole union occupies 4 bytes

int main(){
    S s = {0x12345678};     // initializes the first member, s.n now the active member
    // at this time reading form s.n or s.c is undefined-behavior

    std::cout<<std::hex<<"s.n = "<<s.n<<std::endl;
    s.s[0] = 0x0011;        // s.s is now the active member
    // at this point, reading form n or c is undefined-behavior but most compilers define this
    std::cout<<"s.c is now "<<+s.c<<std::endl   // 11 or 00, depending on platform
             <<"s.n is now "<<s.n<<std::endl;   // 12340011 or 00115567
}

