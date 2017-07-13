/*

A review of map library

*/
/// std::map::insert
//  with hint
//  with range
//  with initializer_list
//  with pair
//
//  Insert elements

#include <iostream>
#include <map>


int main( ){
    typedef std::map< const char*, unsigned > map_t;

    map_t map{
        { "zero", 0 }
    };

    map.insert( map.begin(), { "one", 1 } );    // iterator and pair&&

    map.insert( { "three", 3 } );               // pair&&

    map.insert( { { "five", 5 }, { "six", 6 } } );  // initializer_list

    map_t map2( map.begin(), map.end() );   // range

    for( const auto& pair : map ) std::cout << pair.first << ' ' << pair.second << '\n';

    puts( "#####################" );

    for( const auto& pair : map2 ) std::cout << pair.first << ' ' << pair.second << '\n';


}

/* output

one 1
three 3
zero 0
five 5
six 6
#####################
one 1
three 3
zero 0
five 5
six 6

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


*/
