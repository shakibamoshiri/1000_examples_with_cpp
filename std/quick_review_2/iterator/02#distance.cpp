/*

A review of iterator library


*/

/// distance
//  Returns distance between two iterators.

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

    std::cout << std::distance( begin_array, end_array ) << '\n';
    std::cout << std::distance( end_array , begin_array ) << '\n';

    std::cout << begin_array - end_array << '\n';
    std::cout << end_array - begin_array << '\n';

}

/* output


6
-6
-6
6

Process returned 0 (0x0)   execution time : 0.009 s
Press ENTER to continue.



*/
