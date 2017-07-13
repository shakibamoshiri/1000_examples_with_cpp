/*

A review of iterator library


*/

/// reverse_iterator
//  This class reverse the direction in which a bi-directional or random-access
//  iterator iterates through a range.


#include <iostream>
#include <iterator>




int main(){

    constexpr unsigned array_index_size = 10;
    int array[ array_index_size ] { 1,2,3,4,5,6,7,8,9,10 };
    const int* array_from = array;
    const int* array_upto = array + array_index_size;

    std::reverse_iterator< const int* > r_array_upto( array_from );
    std::reverse_iterator< const int* > r_array_from( array_upto );

    std::cout << "output: ";
    while( r_array_from != r_array_upto ){
        std::cout << *r_array_from++ << ' ';
    }

}
/* output


output: 10 9 8 7 6 5 4 3 2 1
Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



*/
