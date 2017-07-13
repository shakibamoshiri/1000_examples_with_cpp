/*

A review of map library

*/
/// std::map::equal_range
//  pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
//  pair<iterator,iterator>             equal_range (const key_type& k);

//  Gets range of equal element


#include <iostream>
#include <map>


int main( ){
    std::map< const char*, unsigned > map;

    map.emplace( "apple", 3 );
    map.emplace( "kiwi", 4 );
    map.emplace( "banana", 5 );

    std::cout << map.equal_range( "kiwi" ).first->first << '\n';
    std::cout << map.equal_range( "kiwi" ).first->second << '\n';

    std::cout << map.equal_range( "kiwi" ).second->first << '\n';
    std::cout << map.equal_range( "kiwi" ).second->second << '\n';





}

/* output

kiwi
4
banana
5

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


*/
