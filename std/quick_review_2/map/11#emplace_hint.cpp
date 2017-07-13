/*

A review of map library

*/
/// std::map::emplace_hint
//  template <class... Args>
//  iterator emplace_hint (const_iterator position, Args&&... args);
//
//  constructs and insert element with hint


#include <iostream>
#include <map>


int main( ){
    std::map< const char*, unsigned > map;

    map.emplace( "apple", 3 );
    map.emplace( "kiwi", 4 );
    map.emplace( "banana", 5 );

    for( const auto& pair : map ) std::cout << pair.first << ' ' << pair.second << '\n';
    puts( "---------------" );
    map.emplace_hint( map.end(), "grape", 6 );
    for( const auto& pair : map ) std::cout << pair.first << ' ' << pair.second << '\n';





}

/* output

apple 3
kiwi 4
banana 5
---------------
apple 3
kiwi 4
banana 5
grape 6

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


*/
