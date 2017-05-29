/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <vector>




/// partition_copy
//  partition range in two. { copy }


bool is_odd( const int i ){
    return i % 2 == 1;
}

int main(){

    int array[] = { 1,2,3,4,5,6,7,8,9 };
    const unsigned count_result = std::count_if( std::begin( array ), std::end( array ), is_odd );

    int odd_number[ count_result ]{};
    int* begin_odd = odd_number;

    int even_number[ count_result - 1 ]{};
    int* begin_even = even_number;

//    std::vector< int > odd_number( count_result );
  //  std::vector< int > even_number( count_result - 1 );
    std::partition_copy( std::begin( array ), std::end( array ),
                         begin_odd,
                         begin_even,
                         is_odd );

    std::cout << "odd_number: ";
    for( const int i : odd_number )
        std::cout << i << ' ';

    std::cout << "\neven_number: ";
    for( const int i : even_number )
        std::cout << i << ' ';

}

/* output

odd_number: 1 3 5 7 9
even_number: 2 4 6 8
Process returned 0 (0x0)   execution time : 0.034 s
Press ENTER to continue.

*/
