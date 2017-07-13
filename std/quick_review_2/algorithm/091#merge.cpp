/*

A review of algorithm library

merge:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// merge
//  merge sorted range

// return OutputIterator


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

    std::merge( begin_array_1, end_array_1, // first range
                begin_array_2, end_array_2, // second range
                begin_result );             // output

    std::ostream_iterator< int > output( std::cout, " " );
    std::copy( begin_result, end_result, output );

}

/* output


0 1 2 3 4 5 6 7 8 9
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.




*/
