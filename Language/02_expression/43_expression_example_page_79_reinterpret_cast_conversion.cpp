/**

/// Expression
/// Implicit Conversions
/// reinterpret_cast
reinterpret_cast < new_type > ( expression )

Converts between type by reinterpreting the underlying bit patten.
Return a value of new_type

Note:
Unlike static_cast, but like const_cast, the reinterpret_cast does
not compile to any CPU instructions. It is purely a compile directive
which instructs the compiler to treat the sequence of bits ( object
representation ) of expression as if it had the new_type.

**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

int f() {return 42;}
int main(){

    int i = 7;

    // pointer to integer and back
    uintptr_t v1 = reinterpret_cast<uintptr_t>(&i); // static_cast is an error
    std::cout<<"The value of &i is 0x" <<std::hex<<v1<<std::endl;
    int* p = reinterpret_cast<int*>(v1);
    assert(p == &i);

    // pointer to function to another and back
    void (*fp1)() = reinterpret_cast<void(*)()>(f);
    // fp1(); undefined behavior

    /// First we get form void* then covert to int*
    int(*fp2)() = reinterpret_cast<int(*)()>(fp1);
    std::cout<<std::dec<<fp2()<<std::endl; // safe

    // type aliases through pointer
    char* p2 = reinterpret_cast<char*>(&i);
    if(p2[2] == '\x7')
        std::cout<<"This system is little-endian\n";
    else
        std::cout<<"This system is bit-endian\n";

    // type aliasing through reference
    reinterpret_cast<unsigned int&>(i) = 42;
    std::cout<<i<<std::endl;


}













