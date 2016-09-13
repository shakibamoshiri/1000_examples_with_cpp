/// Sequence containers : list
/// std::list
///
///



/// 00_std::list
/// definition in header < list >
/// template < class T, class Allocator = std::allocator<T> > class list;
/**

std::list is a container that supports contents time insertion and removal of
elements form anywhere in the container. Fast random access is not supported.
It is usually implemented as a double-linked list. Compared to std::froward_list
this container provided bidirectional iteration capacity while being lass space
efficient. Addition, removal, and moving the element within the list or across
several lists does not invalidate the iterators or references. An iterator is
invalidated only when the corresponding element is deleted.

Member type:
    value_type
    allocator_type
    size_type
    different_type
    reference
    Allocator::reference
    value_type&
    const_reference
    Allocator_const_reference
    const value_type&
    pointer
    Allocator_pointer
    std::allocator_traits<Allocator>::pointer
    const_pointer
    Allocator::const_pointer
    std::allocator_traits<Allocator>const_pointer
    iterator
    const_iterator
    reverse_iterator
    const_reverse_iterator

Member function
    constructor
    destructor
    operator=
    assign
    get_allocator

Element access
    front
    back

Iterator:
    begin and cbegin    ( constant begin )
    end and cend        ( constant end )
    rbegin and crbegin  ( reverse constant begin )
    rend and crend      ( reverse constant end )

Capacity:
    empty
    size
    max_size

Modifiers:
    clear
    insert
    emplace c++11
    erase
    push_back
    emplace_back c++11
    pop_back
    push_front
    emplace_front c++11
    pop_front
    resize
    swap

Operation:
    merge
    splice
    remove and remove_if
    reverse
    unique
    sort

Non-Member Function
    operator==,!=,<,<=,>,>=
    std::swap ( std::list )

**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>

//#include <unistd.h>



int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
    }

}
