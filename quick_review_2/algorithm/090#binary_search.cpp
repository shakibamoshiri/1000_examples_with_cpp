/*

A review of algorithm library

binary search:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// binary_search
//  test if a value exists in sorted sequence.

// return boolean type


//bool binary_function( int i_1,int i_2 ){
//    return i_1 > i_2;
//}
int main(){

    int array[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
    int* begin_array = array;
    int* end_array   = array + 9;

    std::sort( begin_array, end_array );    // 1 1 1 2 2 2 3 3 3

    bool _3_was_found = std::binary_search( begin_array, end_array, 3 );
    bool _5_was_found = std::binary_search( begin_array, end_array, 5 );

    std::cout << ( _3_was_found ? "yes found" : "No not found" ) << '\n';
    std::cout << ( _5_was_found ? "yes found" : "No not found" ) << '\n';
}

/* output

yes found
No not found

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.





*/
