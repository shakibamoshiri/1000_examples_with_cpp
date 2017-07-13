/*

A review of algorithm library

binary search:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// lower_bound
//  returns an iterator to lower bound.


//bool binary_function( int i_1,int i_2 ){
//    return i_1 > i_2;
//}
int main(){

    int array[] = { 1, 2, 3, 4, 5, -1, -2, -3, -4 };
    int* begin_array = array;
    int* end_array   = array + 9;

    std::sort( begin_array, end_array );

    int* ptr_lower = std::lower_bound( begin_array, end_array, 1 );
    int* ptr_upper = std::upper_bound( begin_array, end_array, 1 );


    std::cout << "lower_bound is: ";
    std::ostream_iterator< int > output( std::cout, " " );
    std::copy( begin_array, ptr_lower, output );
    std::cout << "\nupper_bound is: ";
    std::copy( ptr_upper, end_array, output );
}

/* output

lower_bound is: -4 -3 -2 -1
upper_bound is: 2 3 4 5
Process returned 0 (0x0)   execution time : 0.015 s
Press ENTER to continue.



*/
