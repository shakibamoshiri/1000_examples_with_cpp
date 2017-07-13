/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::not2
//  Returns negation of a binary function object.

#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>  // std::pair

int main(){

    int array_1_[] { 1,2,3,4,5,6,7 };
    int array_2_[] { 1,0,3,4,5,7,6 };

    std::pair< const int*, const int* > first_match_, first_mismatch_;
    first_mismatch_ = std::mismatch( array_1_, array_1_ + 7, array_2_, array_2_ + 7, std::equal_to< int >() );
    first_match_    = std::mismatch( array_1_, array_1_ + 7, array_2_, array_2_ + 7, std::not2( std::equal_to< int >() ) );

    std::cout << "first mismatch: " << *first_mismatch_.first << ' ' << *first_mismatch_.second << '\n';
    std::cout << "first match   : " << *first_match_.first << ' ' << *first_match_.second << '\n';

}

/* output

first mismatch: 2 0
first match   : 1 1

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.

*/
