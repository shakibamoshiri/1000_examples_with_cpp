/*

A review of map library

*/
/// std::map::get_allocator
//  allocator_type get_allocator() const noexcept;
//
//  Gets allocator

#include <iostream>
#include <map>


int main( ){
    unsigned size = 0;
    std::map< const char*, unsigned > map;
    std::pair< const char* const, unsigned >* pair_ptr;

    // allocating an array of 5 elements using map's allocator
    pair_ptr = map.get_allocator().allocate( 5 );

    // get the size
    size = sizeof( std::map< const char*, unsigned > ) * 5;
    std::cout << "The allocator array has the size: " << size << '\n';

    map.get_allocator().deallocate( pair_ptr, 5 );
}

/* output

The allocator array has the size: 120

Process returned 0 (0x0)   execution time : 0.009 s
Press ENTER to continue.


*/
