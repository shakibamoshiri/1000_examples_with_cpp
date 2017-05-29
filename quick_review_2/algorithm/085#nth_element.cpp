/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// nth_element
//  sort element in range


bool binary_function( int i_1,int i_2 ){
    return i_1 > i_2;
}
int main(){

    int array[] = { 1, 2, 3, 4, 5, -1, -2, -3, -4 };
    int* begin_array = array;
    int* end_array   = array + 9;

    std::ostream_iterator< int > output( std::cout, " " );

    std::random_shuffle( begin_array, end_array );

    std::nth_element( begin_array, begin_array + 4, end_array );
    std::copy( begin_array, end_array, output );

    std::random_shuffle( begin_array, end_array );
    std::nth_element( begin_array, begin_array + 4, end_array, binary_function );
    std::cout << '\n';
    std::copy( begin_array, end_array, output );
}

/* output

-2 -4 -3 -1 1 5 3 2 4
3 4 5 2 1 -2 -1 -4 -3
Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.


*/
