/// Sequence containers : set
/// std::set
///
///
/// 00_std::set
/// definition in header < set >

/**
template<class Key,
         class Compare = std::less<Kay>
         class Allocator = std::allocator<Key>
        > class set;

std::set is an associative container that contains a sorted set of "unique"
objects of type 'key'. Sorting is done using key comparison function Compare.
Search, removal, and insertion operations have logarithmic complexity. Sets
are usually implemented as red-black trees.
Everywhere the standard library used the 'compare' concept, uniqueness is
determined by using the equivalence relation. In imprecise terms, two objects
'a' and 'b' are considered equivalent ( not unique ) if neither compares less
than the other: !comp ( a,b) && !comp (b,a).
std::set meets the requirement of Container, AllocatorAwareContainer,AssociativeContainer
and ReversibleContainer.

Member types:
    key_type
    value_type
    size_type
    difference_type
    key_compare
    value_compare
    allocator_type
    reference
    Allocator::reference
    value_type&
    const_reference
    Allocator_const_reference
    const value_type&
    pointer
    Allocator_pointer
    std::allocator_traits<Allocator>::const_pointer
    iterator
    BidirectionalIterator
    constant BidirectionalIterator
    const_iterator
    reverse_iterator
    const_reverse_iterator

Member Function:
    constructor
    destructor
    operator=
    get_allocator

Iterator:
    being and cbeing
    end and cend
    rbegin and rcbegin
    rend and crend

Capacity
    empty
    size
    max_size

Modifiers
    clear
    insert
    emplace
    emplace_hint
    erase
    swap

Lookup
    count
    find
    equal_range
    lower_range
    upper_range

Observers
    key_comp
    value_comp

Non-member function
    operator==,!=,<,>,<=,>=
    set::swap


Note:
    The member types 'iterator' and 'const_iterator' may be aliases to the same type.
    since 'iterator' is convertible to 'const_iterator','const_iterator' should be
    used in function parameter lists to avoid violation of the One Definition

**/


#include <iostream>
//#include <unistd.h>



int main(){
    { /// user sample:
    }
    { /// sample of en.reference.com
    }

}
/* out put */
/*


*/
