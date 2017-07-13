/*

A review of map library

*/
/// std::map::operator = assignment
//  map& operator=( const map& other );
//  map& operator=( map&& other );
//  map& operator=( initializer_list< value_type > ilist )
//
//  copy container content


#include <iostream>
#include <map>


int main( ){
    typedef std::map< const char*, unsigned > map_t;

    map_t first;

    first = {
        { "one", 1 },
        { "two", 2 },
        { "three", 3 }
    };                                      // initializer-list

    map_t second = first;                   // copy


    first = map_t{ { "first", 0 } };        // move

    for( const auto& pair : first ) std::cout << pair.first << ' ' << pair.second << '\n';

    std::cout << '\n';

    for( const auto& pair : second ) std::cout << pair.first << ' ' << pair.second << '\n';



}
/* output

first 0

one 1
two 2
three 3

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
