/*

A review of iterator library


*/

/// reverse_iterator::base
//  iterator_type base() const;
//
//  Return base iterator

#include <iostream>
#include <iterator>




int main(){

    constexpr unsigned array_index_size = 10;
    int array[ array_index_size ] { 1,2,3,4,5,6,7,8,9,10 };
    const int* array_from = array;
    const int* array_upto = array + array_index_size;

    std::reverse_iterator< const int* > r_array_upto { array_from };
    std::reverse_iterator< const int* > r_array_from ( array_upto );

    std::cout << "output: \n";
    for( const int* it = r_array_upto.base(); it != r_array_from.base(); ++it ){
        std::cout << *it << '\n';
    }

}
/* output


output:
1
2
3
4
5
6
7
8
9
10

Process returned 0 (0x0)   execution time : 0.014 s
Press ENTER to continue.


*/
