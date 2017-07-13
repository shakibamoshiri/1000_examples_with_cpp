/*

A review of algorithm library

merge:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// inplace_merge
//  merge consecutive sorted range

// return is: void


//bool binary_function( int i_1,int i_2 ){
//    return i_1 > i_2;
//}
int main(){

    int array_1[] = { 1,3,5,7,9 };
    const int* begin_array_1 = array_1;
    const int* end_array_1 = array_1 + 5;

    int array_2[] = { 0,2,4,6,8 };
    const int* begin_array_2 = array_2;
    const int* end_array_2 = array_2 + 5;

    const unsigned size_index_result = ( end_array_1 - begin_array_1 ) + ( end_array_2 - begin_array_2 );
    int result_of_merge[ size_index_result ];
    int* begin_result = result_of_merge;    // should not be constant expression
    int* end_result = result_of_merge + size_index_result;

    int* middle_point = std::copy( begin_array_1, end_array_1, begin_result );    // 0 to 4 index
                              std::copy( begin_array_2, end_array_2, middle_point );    // 5 to 9 index

    std::inplace_merge( begin_result, begin_result + ( size_index_result / 2 ), end_result );

    std::ostream_iterator< int > output( std::cout, " " );
    std::copy( begin_result, end_result, output );

}

/* output


0 1 2 3 4 5 6 7 8 9
Process returned 0 (0x0)   execution time : 0.010 s
Press ENTER to continue.


*/
