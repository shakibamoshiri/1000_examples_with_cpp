/*

A review of algorithm library

Heap:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// is_heap
//  test if range is heap

// return is: boolean


int main(){

    constexpr unsigned array_index_size = 10;
    int array[ array_index_size ]{ 0, 9, 1, 8, 2, 7, 3, 6, 4, -1 };
    int* begin_array = array;
    int* end_array   = array + array_index_size;

    std::ostream_iterator< int > output( std::cout, " " );

    std::make_heap( begin_array, end_array );
    std::cout << std::is_heap( begin_array, end_array ) << '\n';

    puts( "" );
    array[ array_index_size + -1 ] = 100;
    int* point = std::is_heap_until( begin_array, end_array );
    std::cout << "the range is heap until: ";
    std::copy( begin_array, point, output );


}

/* output


1

the range is heap until: 9 8 7 6 2 1 3 0 4
Process returned 0 (0x0)   execution time : 0.021 s
Press ENTER to continue.


*/
