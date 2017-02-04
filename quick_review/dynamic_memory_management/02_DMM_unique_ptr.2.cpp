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

struct D {  // deleter
    void operator()( S* ptr ){
        puts( "D was deleted" );
        delete ptr;
    }
}deleter;

int main(){

    {
        std::unique_ptr< S > uptr( new S() );   // both together
    }

    // with deleter
    {
        std::unique_ptr< S, D > uptr( new S(), deleter );   // deleter copied
    }
}
/* output:

default constructor...
destructor...
default constructor...
D was deleted
destructor...


*/
