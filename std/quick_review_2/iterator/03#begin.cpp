/*

A review of iterator library


*/

/// begin
//  iterate to the beginning

#include <iostream>
#include <iterator>

template< typename T, unsigned int N >
T* begin_of( T ( &array )[ N ] ){
    return array;
}
template< typename T, unsigned int N >
T* end_of( T ( &array )[ N ] ){
    return array + N;
}


int main(){

    char array[] = "hello";
    char* begin_array = begin_of( array );
    char* end_array   = end_of( array );

    std::cout << ( begin_array == std::begin( array ) ? "equal" : "not equal" ) << '\n';
    std::cout << ( end_array   == std::end( array ) ? "equal" : "not equal" ) << '\n';

}

/* output


equal
equal

Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.


*/
