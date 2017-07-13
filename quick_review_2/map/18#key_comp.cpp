/*

A review of map library

*/
/// std::map::key_comp
//  key_compare key_comp() const
//
//  return key comparison object

#include <iostream>
#include <map>


int main( ){
    typedef std::map< const char*, unsigned > map_t;

    map_t map;
    map_t::key_compare user_key_compare = map.key_comp();

    map[ "one" ]   = 1;
    map[ "three" ] = 3;
    map[ "two" ]   = 2;
    map[ "five" ]  = 5;
    map[ "four" ]  = 4;

    map_t::iterator iter =  map.begin();
    const char* highest = map.rbegin()->first;

    do{
        std::cout << iter->first << ' ' << iter->second << '\n';
    }while( user_key_compare( ( *iter++ ).first, highest ) );


}
/* output

one 1
three 3
two 2
five 5
four 4

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


*/
