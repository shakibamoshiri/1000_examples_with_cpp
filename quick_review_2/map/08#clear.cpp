/*

A review of map library

*/
/// std::map::clear
//  void clear() noexcept;
//
//  clear the content of a object


#include <iostream>
#include <map>


int main( ){

    const char* array_of_string[]{ "one", "two", "two", "three", "three", "three", '\0' };

    std::map< const char*, unsigned > map;

    for( const char* str : array_of_string ) map[ str ]++;

    std::map< const char*, unsigned >::iterator iter = map.begin();
    ++iter; // skipping '\0' the null-terminate-character


    for( ;iter != map.end(); ++iter ) std::cout << iter->first << ' ' << iter->second << '\n';

    map.clear();
    if ( map.empty() ) std::cout << "now map is empty\n";


}

/* output


one 1
two 2
three 3
now map is empty

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.

*/
