/*

A review of iterator library


*/

/// istream_iterator
//  input stream iterator

#include <iostream>
#include <iterator>
#include <algorithm>



int main(){

    double d1, d2;
    std::cout << "Enter two values: ";
    std::istream_iterator< double > end_of_stream;  // be default
    std::istream_iterator< double > start_of_stream( std::cin );

    if( start_of_stream != end_of_stream )
        d1 = *start_of_stream;

    ++start_of_stream;

    if( start_of_stream != end_of_stream )
        d2 = *start_of_stream;

    std::cout << "you entered: " << d1 << " and " << d2 << '\n';

}
/* output

Enter two values: 12 43
you entered: 12 and 43

Process returned 0 (0x0)   execution time : 3.210 s
Press ENTER to continue.


*/
