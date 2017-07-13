/*

A review of iterator library


*/

/// back_inserter
//  construct a back insert iterator

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template< typename T >
T* begin_of( T* &c_string ){
    return c_string;
}
template< typename T >
T* end_of( T* &c_string ){
    return c_string + std::char_traits< char >::length( c_string );
}


int main(){

    const char* array = "hello";
    const char* begin_array = begin_of( array );
    const char* end_array   = end_of( array );


    std::vector< char> copy_of_array;

    std::copy( begin_array, end_array, std::back_inserter( copy_of_array ) );

    for( const char chr : copy_of_array ){
        std::cout << chr;
    }

}

/* output


hello
Process returned 0 (0x0)   execution time : 0.033 s
Press ENTER to continue.


*/
