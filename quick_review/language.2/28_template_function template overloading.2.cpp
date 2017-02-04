/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 2. template
//  function template overloading

/******************/
#include <iostream>
/******************/

template< typename T > void function( T obj, T* obj_ptr )
{ std::cout << "match one " << obj << obj_ptr << '\n'; }      // one

template< typename T > void function( T obj, int* obj_ptr )
{ std::cout << "match two " << obj << obj_ptr << '\n'; }      // two



int main(){

    int number = 10;
    const int* ptr = &number;

    // error
//    function( 10, "char*" );    // it can be int and int* not can be int and char*

//    function( 10, ptr );        //it can wanted to call int and int* &, there is not match

    const char* name = "c++";
//    function( number, name );   // like first ( 10, "char*" )

    // error ambiguous
//    function( 10, &number );

    char* chptr = nullptr;
    function( 'c', chptr );   // calls one  both type is char, and char*

    // error
//    function( 'c', "char*" );   // will not call because "char*" is const char [6]

    // error
//    function( number, &number );    // complier is ambiguous

    // error
//    function( 11, &number );      // compiler is ambiguous

    /// Neither is more specialized
    /// calls to two is ambiguous

}

/* output:


*/
