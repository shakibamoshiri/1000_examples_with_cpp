/*

A review of iterator library


*/

/// advance
//  Advance iterator

// return: void

#include <iostream>
#include <iterator>

template< typename T, unsigned int N >
T* end_of(T ( &array )[ N ] ){
    return array + N;
}


int main(){

    char array[] = "hello";
    char* begin_array = array;
    char* end_array   = end_of( array );

    std::advance( begin_array, 4 );

    std::cout << *begin_array << '\n';

}

/* output


o

Process returned 0 (0x0)   execution time : 0.015 s
Press ENTER to continue.



*/
