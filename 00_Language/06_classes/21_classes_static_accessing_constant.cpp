/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    * static specifier              - bit field
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
    static specifier
    Inside a class, declares members not bound to specific instances ( instance means: a particular example or case of something )

    syntax:
    static data member      : declares a static data member
    static function member  : declares a static function member

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// constant static member
// If a static member of integral or enumeration type is declared cosnt
// ( and not volatile ), it can be initialized with a brace-or-equal
// initializer that is a constant expression., right inside the class definition:

struct X {
    const static int n = 1;     // okay
    const static int m{2};      // okay
};
// also it possible for constexpr
struct Y {
    constexpr static int a = 0; // okay
    constexpr static int b{1};  // okay
};

/// always need to definition even if, it has initializer inside the struct
struct M {
    const static int s = 20;
};
const int M::s;     // it is necessary, but it should not have an initializer
const int* p = &M::s;   // M::s is odr-used

int main(){

}
