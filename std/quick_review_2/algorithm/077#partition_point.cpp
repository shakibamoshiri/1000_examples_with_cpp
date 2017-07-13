/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// partition_point
//  get partition point


bool is_odd( const int i ){
    return i % 2 == 1;
}

int main(){

    int array[] = { 1,2,3,4,5,6,7,8,9 };
    const int* b_it = array;
    const int* e_it = array + 9;

    std::partition( std::begin( array ), std::end( array ), is_odd );

    const int* point = std::partition_point( std::begin( array ), std::end( array ), is_odd );

    std::copy( b_it, point, std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << '\n';

    std::copy( point, e_it , std::ostream_iterator< int >( std::cout, " " ) );



}

/* output


1 9 3 7 5
6 4 8 2
Process returned 0 (0x0)   execution time : 0.010 s
Press ENTER to continue.



*/
