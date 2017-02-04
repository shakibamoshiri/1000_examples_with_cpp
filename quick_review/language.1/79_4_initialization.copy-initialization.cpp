/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// initialization

#include <iostream>
#include <utility>
#include <memory>



int main(){
    std::string string = "this is a string";        // okay constructor is non-explicit

//    std::unique_ptr< int > uptr = new int( 1 );     // error: the constructor is explicit
    std::unique_ptr< int > uptr( new int( 1 ) );     // okay: direct-initialization


}



/* output:


*/
