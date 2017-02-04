/*
    quick review:

    Language Support
        01. type support
        02. dynamic memory management
        03. error handling
        04. initializer-list
        05. variadic function
    **********************************

*/
/// 02. dynamic memory management
//
//  std::unique_ptr

#include <iostream>
#include <memory>


struct S {
    S(){ puts( "default constructor..." ); }
    ~S(){ puts( "destructor..." ); }
};


int main(){

    S* ptr_1 = new S(); // default constructor...
    delete ptr_1;       // destructor...

    std::unique_ptr< S > uptr_1( new S() ); // both together
}
/* output:

default constructor...
destructor...
default constructor...
destructor...

*/
