/*

A review of algorithm library

Other( or miscellaneous )

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// next_permutation
//  Transform range to the next permutation.

// return is: boolean.

template< typename T, unsigned int N >
T* end_of(T ( &array )[ N ] ){
    return array + N;
}


int main(){

    char array[] = "hello";
    char* begin_array = array;
    char* end_array   = end_of( array );

    bool result_of_permutation = std::next_permutation( begin_array, end_array );

    if( result_of_permutation ){
        for( const char chr : array ) std::cout << chr;
    } else {
        std::cout << "next_permutation was failed\n";
    }

}

/* output

helol
Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.



*/
