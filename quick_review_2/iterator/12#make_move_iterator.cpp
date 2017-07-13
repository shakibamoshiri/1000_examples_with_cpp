/*

A review of iterator library


*/

/// make_move_inserter
//  construct a move iterator

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template< typename T >
T* begin_of( T* &c_string ){
    return c_string;
}
template< typename T >
T* end_of( T* &c_string ){
    return c_string + std::char_traits< char >::length( c_string );
}


int main(){

    std::vector< std::string > vec_1{ "one", "two", "three" };
    std::vector< std::string > vec_2( vec_1.size() );


    std::copy( std::make_move_iterator( vec_1.begin() ), std::make_move_iterator( vec_1.end() ),
               vec_2.begin() );

    std::cout << "vec_1: ";
    for( const std::string str : vec_1 )
        std::cout << str << ' ';

    std::cout << '\n';

    std::cout << "vec_2: ";
    for( const std::string str : vec_2 )
        std::cout << str << ' ';


}

/* output


vec_1:
vec_2: one two three
Process returned 0 (0x0)   execution time : 0.022 s
Press ENTER to continue.


*/
