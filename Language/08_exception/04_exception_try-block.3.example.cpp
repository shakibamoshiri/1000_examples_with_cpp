/*
Exception:
    01
    02 try-block
    03 function-try-block
    04 noexcept specifier ( since c++11 )
    05 noexcept operator  ( since c++11 )
    06 dynamic exception specifier

    For More Detail Read Main Site = f m d r m s
*/
#include <iostream>
#include <exception>
#include <vector>
/// 02 try-block
// Associates one or more exception handlers ( catch-clauses ) with a compound statement
//
// syntax:
// try compound-statement handler-sequence
//
// where hander-sequence is a sequence of one or more handlers, which have the following syntax:
//
// 1 catch ( attribute (optional) type-specifier-sequence declarator ) compound statement
// 2 catch ( attribute (optional) type-specifier-sequence declarator (optional) ) compound statement
// 3 catch ( ... ) compound statement
//
//
//
/** Example **/
// the following example demonstrates several usage cases of the try-catch block

int main(){
    try {
        std::cout<<"Throwing an integer exception ... \n";
        throw 33;
    } catch ( int err ){
        std::cout<<"The integer exception was caught, with value: "<<err<<std::endl;
    }

    try {
        std::cout<<"Catching a vector of size 5 ... \n";
        std::vector<int> v(5);
        std::cout<<"Accessing the 11th element of the vector ... \n";

        std::cout<<v.at(10);                // vector:;at() throw std::out_of_range

    } catch ( const std::exception& err ){  // catch by reference to base
        std::cout<<" a standard exception was caught, with message "
                 <<err.what()
                 <<std::endl;
    }
}
