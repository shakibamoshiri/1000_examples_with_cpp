/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// partially_sort
//  partially sort elements in range


int main(){

    int array[] = { 0,1,2,3,4,5,6,7,8,9 };
    int* begin_array = array;
    int* end_array   = array + 10;
    std::ostream_iterator< int > output( std::cout, " " );

    std::random_shuffle( begin_array, end_array );
    std::copy( begin_array, end_array, output );

    std::cout << '\n';

    std::partial_sort( begin_array, begin_array + 5, end_array );
    std::copy( begin_array, end_array, output );


}

/* output

4 3 7 8 0 5 2 1 6 9
0 1 2 3 4 8 7 5 6 9
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
