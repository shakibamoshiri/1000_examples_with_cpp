/*

A review of map library

*/
/// std::map::count
//  size_type count( const key_type& k ) const
//
//  Counts element with a specific key


#include <iostream>
#include <map>


int main( ){

    const char* array_of_string[]{ "orange", "banana", "banana", "apple", "apple", "apple", '\0' };
    const char* array_of_fruit[]{ "banana", "apple", "kiwi", '\0' };

    std::map< const char*, unsigned > map;

    for( const char* str : array_of_string ) map[ str ]++;

    const char** string_ptr = array_of_string;
    const char** fruit_ptr  = array_of_fruit;

    while( *string_ptr++ ){
        if( map.count( *fruit_ptr ) ){  // return 1 or 0
            std::cout << "fruit: " << *fruit_ptr << '\n';
        }
        ++fruit_ptr;
    }


}

/* output

fruit: banana
fruit: apple
fruit:
Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.


*/
