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
//  non-deduced context


/******************/
#include <iostream>
#include <vector>
/******************/

template< typename T > void print_vector( std::vector< T > vector )
{ for( T temp : vector ) std::cout << temp << ' '; }

template< typename T > void print_vector( std::vector< T > vector, T )
{ for( T temp : vector ) std::cout << temp << ' '; }


int main(){

    // error
//    print_vector( { 1,3,5 } );  // why, template cannot deduced T from { 1,3,5 }

    // okay
    print_vector( { 1,2,3 }, 1 );    // 1 helps the template to deduce which okay, t is int

}

/* output:

1 2 3

*/
