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

    puts( "--------before-moving--------" );

    std::unique_ptr< S > uptr_1( new S() );

    puts( "--------after-moving--------" );

    std::unique_ptr< S > uptr_2 = std::move( uptr_1 );

}
/* output:

--------before-moving--------
default constructor...
--------after-moving--------
destructor...



*/
