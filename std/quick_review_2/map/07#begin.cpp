/*

A review of map library

*/
/// std::map::begin
//        iterator begin()       noexcept;
//  const_iterator begin() const noexcept;
//
//  Return iterator to beginning
//
///  note:
//  Because map containers keep their elements ordered at all times, begin points to the element that
//  goes first following the container's sorting criterion.


#include <iostream>
#include <map>


int main( ){

    const char* array_of_string[]{ "one", "two", "two", "three", "three", "three", '\0' };

    std::map< const char*, unsigned > map;

    for( const char* str : array_of_string ) map[ str ]++;

    std::map< const char*, unsigned >::iterator iter = map.begin();
    ++iter; // skipping '\0' the null-terminate-character


    for( ;iter != map.end(); ++iter )
        std::cout << iter->first << ' ' << iter->second << '\n';


}

/* output

one 1
two 2
three 3

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


*/
