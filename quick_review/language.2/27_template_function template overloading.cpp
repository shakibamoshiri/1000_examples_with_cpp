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

template< typename T > void function( T obj ){ std::cout << "match one " << obj << '\n'; }      // one
template< typename T > void function( T* obj ){ std::cout << "match two " << obj << '\n'; }     // two
template< >            void function( int obj ){ std::cout << "match three " << obj << '\n'; }  // three | the template <> can be omitted
// equivalent to
//                     void function( int obj ){ std::cout << "match three " << obj << '\n'; }


int main(){

    int number = 10;
    function( number ); // match three              int

    int* ptr = &number;
    function( ptr );    // match two                T*

    function( 'c' );    // match one                T

    function( "cosnt char*" );  // match two        T*

    function( 11 );     // match three              int

    function( 1.1 );    // match one                T

    std::size_t size;   // unsigned int
    function( size );   // match one                T

    const int ci = 12;
    function( ci );     // match three              T ( const specifier is omitted )

    int** ptr2 = nullptr;
    function( ptr2 );   // match two                T*
}

/* output:


*/
