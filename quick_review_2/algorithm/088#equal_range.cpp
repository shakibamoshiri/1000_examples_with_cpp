/*

A review of algorithm library

binary search:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// equal_range
//  Get subrange of equal element


//bool binary_function( int i_1,int i_2 ){
//    return i_1 > i_2;
//}
int main(){

    int array[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
    int* begin_array = array;
    int* end_array   = array + 9;

    std::sort( begin_array, end_array );    // 1 1 1 2 2 2 3 3 3

//    int* ptr_lower = std::lower_bound( begin_array, end_array, 2 );
//    int* ptr_upper = std::upper_bound( begin_array, end_array, 2 );

    std::pair< int*, int* > eb = std::equal_range( begin_array, end_array, 2 );

    std::ostream_iterator< int > output( std::cout, " " );

    std::copy( eb.first, eb.second, output );
}

/* output

2 2 2
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
