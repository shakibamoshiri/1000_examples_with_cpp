/*

A review of map library

*/
/// std::map::operator = assignment
//  mapped_type& operator[] (const key_type& k);
//  mapped_type& operator[] (key_type&& k);
//
//  access element
//
/// note
//  A similar member function, map::at, has the same behavior when an element with the key exists,
//  but throws an exception when it does not.

#include <iostream>
#include <map>


int main( ){
    typedef std::map< const char*, unsigned > create_map;

    const char* array[]{ "you", "you", "she", "he", "he", "they", "they", "they" };

    create_map map;
    for( const char* str : array ) map[ str ]++;

    for( const char* str : array ) std::cout << str << " : " << map.at( str ) << '\n';




}
/* output

you : 2
you : 2
she : 1
he : 2
he : 2
they : 3
they : 3
they : 3

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.



*/
