/*

A review of iterator library


*/

/// inserter
//  construct an insert iterator

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

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


    std::list< char> copy_of_array;
    copy_of_array.push_back( 'a' );
    copy_of_array.push_back( 'b' );
    copy_of_array.push_back( 'c' );
    copy_of_array.push_back( ' ' );
    copy_of_array.push_back( ' ' );
    copy_of_array.push_back( ' ' );
    std::list< char >::iterator it_list = copy_of_array.end()--;

    std::copy( begin_array, end_array, std::inserter( copy_of_array, it_list) );

    for( const char chr : copy_of_array ){
        std::cout << chr;
    }

}

/* output


abc   hello
Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.


*/
