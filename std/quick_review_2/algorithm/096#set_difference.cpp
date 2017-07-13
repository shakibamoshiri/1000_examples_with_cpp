/*

A review of algorithm library

merge:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// set_difference
//  Difference of two sorted range

// return is: OutputIterator


int main(){

    constexpr unsigned odd_index_size = 5;
    const int odd[ odd_index_size ]{ 1,2,3,5,7 };
    const int* begin_odd = odd;
    const int* end_odd   = odd + odd_index_size;

    constexpr unsigned even_index_size = odd_index_size;
    const int even[ even_index_size ]{ 2,3,4,6,8 };
    const int* begin_even = even;
    const int* end_even   = even + even_index_size;

    constexpr unsigned result_index_size = odd_index_size + even_index_size;
    int result[ result_index_size ]{};  // 0 0 0 0 0 0 0 0 0 0
    int* begin_result = result;
    int* end_result   = result + result_index_size;

    // if the range was not sorted it should be sorted before using std::set_union
    // here the two range are already sorted

    int* end_point =                  // the end of setting the elements
    std::set_difference( begin_odd, end_odd,     // first range
                    begin_even, end_even,   // second range
                    begin_result );

    std::ostream_iterator< int > output( std::cout, " " );
    std::cout << "result: ";
    std::copy( begin_result, end_point, output );
    std::cout << "\nthe rest: ";
    std::copy( end_point, end_result, output );

}

/* output

result: 1 5 7
the rest: 0 0 0 0 0 0 0
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
