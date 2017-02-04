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
//  std::addressof
//  obtains the actual address of the object of function arg, even in presence of overloading operator&
#include <iostream>
#include <memory>



int main(){

    int* ptr = new int( 10 );
    std::cout << *ptr << '\n';
    std::cout << ptr << '\n';
    std::cout << &ptr << '\n';
    std::cout << std::addressof( ptr ) << '\n';

    delete ptr;


}
/* output:



*/
