/*

A review of map library

*/
/// std::map::


#include <iostream>
#include <map>


int main( ){

    const char* array_of_string[]{ "one", "two", "two", "three", "three", "three", '\0', 0 };

    std::map< const char*, unsigned > map;

    for( const char* str : array_of_string ) map[ str ]++;

    std::map< const char*, unsigned >::iterator iter = map.begin();
    ++iter;


//    std::cout << iter->first << ' ' << iter->second << '\n';
//    return 0;

    for( ; iter != map.end(); ++iter )
        std::cout << iter->first << ' ' << iter->second << '\n';


}

/* output




*/
