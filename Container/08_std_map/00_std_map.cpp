/// Sequence containers : set
/// std::map
///
///
/// 00_std::map
/// definition in header < map >

/**
template<
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key,T>
        > class map;

std::map is a sorted associative container that contains key-value
pairs with unique keys. Keys are sorted by comparison function 'compare'
Search, removal, and insertion operation have logarithmic complexity.
Maps are usually implemented as red-black-trees.

Member types
    key_type
    mapped_type
    value_type
    size_type
    difference_type
    key_compare
    allocator_type
    reference
    Allocator::reference
    value_type&
    const_reference
    Allocator::const_reference
    const value_type&
    pointer
    Allocator::pointer
    std::allocator_traits<Allocator>::pointer
    const_pointer
    Allocator::const_pointer
    std::allocator_traits<Allocator>::const_pointer
    iterator
    const_iterator
    reverse_iterator
    const_reverse_iterator

Member class
    value_comp -> compare objects of type value_type

Member function
    constructor -> constructs the map.
    destructor -> destructs the map.
    operator= -> assigns value to the container.
    get_allocator -> returns the associated allocator.

Element Access
    at -> access specified element with bounds checking.
    operator[] -> access specified element.

Iterator
    begin / cbeging -> returns an iterator to the beginning.
    end / cend -> returns an iterator to the end.
    rbegin / cebegin -> returns a reverse iterator to the beginning.
    rend / rcend -> returns a reverse iterator to the end.

Capacity
    empty -> checks whether the container is empty.
    size -> returns the member of elements.
    max_size -> returns the maximum possible number of elements.

Modifiers
    clear -> clears the contents.
    insert -> inserts elements.
    insert_or_assign -> inserts an element or assigns to the current element if the key already exists.
    emplace -> constructs elements in-place
    emplace_hint -> constructs elements in-place using a hint
    erase -> erases element.
    swap -> swaps the contents.

Lookup
    count -> returns the number of elements matching specific key.
    find -> finds element with specific key.
    equal_range -> returns range of elements matching specific key.
    lower_bound -> returns an iterator to the first element not less than the given key.
    upper_bound -> returns an iterator to the first element greater than the given key.

Observes
    key_comp -> returns the function that compares keys.
    value_comp -> returns the function that compares the keys in objects of type value_type.

Non-member function
    operator comparison ==, !=, <, > <=, >= -> lexicographically compares the values in the map.
    std::swap ( std::map ) -> specializes the std::swap algorithms


**/


//#include <unistd.h>
#include <iostream>
#include <string>
#include <map>


int main(){


    { /// my sample

    }
    { /// en.reference.com

    }


}
