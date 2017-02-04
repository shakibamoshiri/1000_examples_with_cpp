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
//  std::shared_ptr

#include <iostream>
#include <memory>


struct S {
    static int counter;
    S(){
        ++counter;
        std::cout << counter;
        puts( "  default constructor..." );}
    ~S(){
        std::cout << counter;
        puts( "  destructor..." );
        --counter;
    }
};
int S::counter = 0;


struct D {  // deleter
    void operator()( S* ptr ){
        puts( "D was deleted" );
        delete ptr;
    }
}deleter;

int main(){

    std::shared_ptr< S > shptr_1( new S() );
    std::shared_ptr< S > shptr_2( shptr_1 );
    std::shared_ptr< S > shptr_3( new S(), deleter );

}
/* output:

1  default constructor...
2  default constructor...
D was deleted
2  destructor...
1  destructor...

*/
