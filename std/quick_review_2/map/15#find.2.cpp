/*

A review of map library

*/
/// std::map::find
//       iterator find (const key_type& k);
// const_iterator find (const key_type& k) const;
//
//  Gets iterator to a elmeent

#include <iostream>
#include <map>


int main( ){
    const char* array[] { "one", "two", "two", "three", "three", "three" };

    std::map< const char*, unsigned > map;
    for( const char* str : array ) map[ str ]++;

    std::cout << map.find( "two" )->first << '\n';
    std::cout << map.find( "two" )->second << '\n';

    std::cout << map.find( "three" )->first << '\n';
    std::cout << map.find( "three" )->second << '\n';







}

/* output

two
2
three
3

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



*/
