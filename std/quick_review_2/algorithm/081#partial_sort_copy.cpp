/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// partially_sort
//  partially sort elements in range


bool binary_function( const int i_1, const int i_2 ){
    return i_1 < i_2;
}
int main(){

    int array[] = { 0,1,2,3,4,5,6,7,8,9 };
    int* begin_array = array;
    int* end_array   = array + 10;
    std::ostream_iterator< int > output( std::cout, " " );

    std::random_shuffle( begin_array, end_array );
    std::copy( begin_array, end_array, output );

    std::cout << '\n';
    int array_2[ 5 ]{};
    int* begin_array_2 = array_2;
    int* end_array_2 = array_2 + 5;

    std::partial_sort_copy( begin_array, end_array, begin_array_2, end_array_2, binary_function );
    std::copy( begin_array_2, end_array_2, output );


}

/* output

4 3 7 8 0 5 2 1 6 9
0 1 2 3 4
Process returned 0 (0x0)   execution time : 0.017 s
Press ENTER to continue.

*/
