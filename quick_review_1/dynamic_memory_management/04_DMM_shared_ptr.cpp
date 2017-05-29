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
//

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

    std::shared_ptr< S > shptr_1( new S() );    // use_count == 1
    std::shared_ptr< S > shptr_2( shptr_1 );    // use_count == 2
    std::shared_ptr< S > shptr_3( shptr_2 );    // use_count == 3

    puts( "--------------" );
    std::cout << shptr_3.use_count() << '\n';   // 3

}
/* output:



*/
