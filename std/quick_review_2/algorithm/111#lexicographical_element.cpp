/*

A review of algorithm library

Other( or miscellaneous )

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// lexicographical_compare
//  Lexicographical less-than comparison

// Return value
// true if the first range compares lexicographically less than than the second.
// false otherwise (including when all the elements of both ranges are equivalent).

const char* end_of( const char* &array ){
    return array + std::char_traits< char >::length( array );
}

char to_lower( const char chr ){
    return ( chr >= 'A' && chr <= 'Z' ? chr + 32 : chr );
}
bool case_insensitive( const char ch_1, const char ch_2 ){
//    return to_lower( ch_1 ) < to_lower( ch_2 );
    return ch_1 < ch_2;
}
int main(){

    const char* apple_1 = "apple";
    const char* begin_apple_1 = apple_1;
    const char* end_apple_1   = end_of( apple_1 );

    const char* apple_2 = "APPLE";
    const char* begin_apple_2 = apple_2;
    const char* end_apple_2   = end_of( apple_2 );

    bool result_1 = std::lexicographical_compare( begin_apple_1, end_apple_1, begin_apple_2, end_apple_2 );
    bool result_2 = std::lexicographical_compare( begin_apple_1, end_apple_1, begin_apple_2, end_apple_2, case_insensitive );

    std::boolalpha( std::cout );
    std::cout << result_1 << '\n';
    std::cout << result_2 << '\n';

}
/// Actually I could not understand this algorithm
/* output



false
false

Process returned 0 (0x0)   execution time : 0.018 s
Press ENTER to continue.


*/
