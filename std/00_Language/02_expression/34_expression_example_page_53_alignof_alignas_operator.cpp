/**

/// Expression
/// alignof (type-id )
Return a value of type std::size_t

explanation:
Returns the alignment in bytes, required for any instance of the type
included by type-id, which is either complete type, an array type, or
a reference type.
If the type is reference type, the operator returns the alignment of
referenced type, if the type is array type, alignment requirement of
the element type is returned.

**/
#include <iostream>
#include <string>
#include <array>
/// user defined
//#include "temp.h"

struct Foo{
    int i;
    float f;
    char c;
};
struct Empty{};

struct alignas(64) Empty64 {};

struct alignas(1) Double {
    double d;
};

int main(){
    std::cout<<"Alignment of\n"
             <<"-char               : "<<alignof(char)      <<std::endl
             <<"-pointer            : "<<alignof(int*)      <<std::endl
             <<"-class Foo          : "<<alignof(Foo)       <<std::endl
             <<"-empty class        : "<<alignof(Empty)     <<std::endl
             <<"-alignas(64) Empty  : "<<alignof(Empty64)   <<std::endl
             <<"-alignas(1) Double  : "<<alignof(Double)    <<std::endl;
}













