/*

A review of map library

*/
/// std::map::at
//  access element.


#include <iostream>
#include <map>


int main( ){

    const char* array_of_string[]{ "one", "two", "two", "three", "three", "three", '\0' };

    std::map< const char*, unsigned > map;
    for( const char* str : array_of_string ) map[ str ]++;

    const char** iterator = array_of_string;


    while( *iterator ){
        std::cout << map.at( *iterator++ )  << '\n';
    }


}

/* output

1
2
2
3
3
3

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.


*/
