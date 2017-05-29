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
    std::cout << std::is_heap( begin_array, end_array ) << '\n';


}

/* output

1

0

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.





*/
