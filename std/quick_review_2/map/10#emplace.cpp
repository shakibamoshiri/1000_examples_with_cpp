/*

A review of map library

*/
/// std::map::count
// template <class... Args>
//      pair<iterator,bool> emplace (Args&&... args);
//
//  constructs and insert element


#include <iostream>
#include <map>


int main( ){
    std::map< const char*, unsigned > map;

    map.emplace( "apple", 3 );
    map.emplace( "kiwi", 4 );
    map.emplace( "banana", 5 );

    for( const auto& pair : map ) std::cout << pair.first << ' ' << pair.second << '\n';





}

/* output

apple 3
kiwi 4
banana 5

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


*/
