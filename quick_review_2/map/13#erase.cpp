/*

A review of map library

*/
/// std::map::erase
//  iterator erase (const_iterator position);
//  size_type erase (const key_type& k);
//  iterator erase (const_iterator first, const_iterator last);
//
//  Erase element

#include <iostream>
#include <map>


int main( ){
    std::map< const char*, unsigned > map;

    map.emplace( "apple", 3 );
    map.emplace( "kiwi", 4 );
    map.emplace( "banana", 5 );

    // return an iterator pointing to the key place
    // map.find( "kiwi" );

    map.erase( map.find( "kiwi" ) );

    for( const auto& pair : map ) std::cout << pair.first << ' ' << pair.second << '\n';





}

/* output

apple 3
banana 5

Process returned 0 (0x0)   execution time : 0.005 s
Press ENTER to continue.



*/
