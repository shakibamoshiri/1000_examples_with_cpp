/*

A review of algorithm library

Partition:

*/


#include <iostream>
#include <algorithm>
#include <iterator>




/// is_sorted
//  checks whether range is sorted


//bool binary_function( const int i_1, const int i_2 ){
//    return i_1 < i_2;
//}
int main(){

    int array[] = { 1,3,2 };
    int* begin_array = array;
    int* end_array   = array + 3;

    std::ostream_iterator< int > output( std::cout, " " );

    std::random_shuffle( begin_array, end_array );
    std::copy( begin_array, end_array, output );
    std::cout << "\n\n";

    do{
        std::prev_permutation( begin_array, end_array );

        // print array:
        std::cout << "array: ";
        for( const int i : array ) std::cout << i << ' ';
        std::cout << '\n';


    }while( !std::is_sorted( begin_array, end_array ) );
    std::cout << "the rang is sorted\n";


}

/* output

1 2 3

array: 3 2 1
array: 3 1 2
array: 2 3 1
array: 2 1 3
array: 1 3 2
array: 1 2 3
the rang is sorted

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.



*/
