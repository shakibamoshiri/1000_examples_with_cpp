/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// is_sorted_until
//  find first unsorted element in range


//bool binary_function( const int i_1, const int i_2 ){
//    return i_1 < i_2;
//}
int main(){

    int array[] = { 1, 2, 3, 4, 5, -1, -2, -3, -4 };
    const int* begin_array = array;
    const int* end_array   = array + 9;

    std::ostream_iterator< int > output( std::cout, " " );

    const int* point = std::is_sorted_until( begin_array, end_array );

    std::cout << "sorted: ";
    std::copy( begin_array, point, output );
    std::cout << "\n\nnot sorted: ";
    std::copy( point, end_array, output );

}

/* output

sorted: 1 2 3 4 5

not sorted: -1 -2 -3 -4
Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



*/
