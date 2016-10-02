/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.

Defined in header <algorithm>

Non-modifying sequence operation
    all_of
    any_of
    noun_of             check, if the predicate is true for all, any, or none of the element is a range

    for_each            applies a function to a range of element

    count
    count_if            return the number of elements satisfying specific criteria

    mismatch            find the first position, where to ranges differ

    equal               determines if two set of elements are the same

    find
    find_if
    find_if_not         find the first element satisfying specific criteria

    find_end            find the last sequence of elements in certain range

    find_first_of       search for any one of a set of elements

    adjacent_find       find the first two adjacent items that are equal (or satisfy a given predicate)

    search              searches for a range of elements

    search_n            search for a number consecutive copies of an element in a range.


Modifying sequence operation

    copy
    copy_if             copies a range of elements to a new location

    copy_n              copies a number of elements to a new location

    copy_backward       copies a range of elements in backward order

    move                moves a range of elements to a new location

    move_backward       moves a range of elements to a new location in backward order

    fill                assigns a range of elements a certain value

    fill_n              assigns a value to a number of elements

    transform           applies a function to a range of elements

    generate            saves the result of a function in a range

    generate_n          saves the result of N applications of a function

    remove
    remove_if           removes elements satisfying specific criteria

    remove_copy
    remove_copy_if      copies a range of elements omitting those that satisfy specific criteria

    replace
    replace_if          replaces all value satisfying specific criteria with another value

    replace_copy
    replace_copy_if     copies a range, replacing elements satisfying specific criteria with another value

    swap                swaps the value of two objects

    swap_range          swaps the two range of elements

    iter_swap           swaps the elements pointed to by two iterator

    reverse             reverses the order of elements in a ragne

    reverse_copy        creates a copy of a range that is reversed

    rotate              rotate the order of elements in a range

    rotate_copy         copies and rotate a range of elements

    shuffle
    random_shuffle      randomly re-orders elements in a range

    (until c++ 17)(c++11)

    unique              removes consecutive duplicate element in a range

    unique_copy         creates a copy a of some range of elements that contains no consecutive duplicate


Partitioning Operation

    is_partitioned      determines if the range is partitioned by the give predicate

    partition           divides a range of elements into two groups

    partition_copy      copies a range dividing the elements into two groups

    stable_partition    divides elements into two groups while preserving their relative order

    partition_point     locates the partition point of a partitioned range


Sorting Operation

    is_sorted           checks whether a range is sorted into according order

    is_sorted_until     finds the largest sorted subrange

    sort                sorts a range into according order

    partial_sort        sorts the first N elements of a range

    partial_sort_copy   copies and partially sort a range of elements

    stable_sort         sorts a range of elements while preserving order between equal elements

    nth_elements        partially sorts the given range making sure that it is partitioned by the given elements


Binary Search operation ( on sorted range )

    lower_bound         returns the iterator to the first elements not less then the given value

    upper_bound         returns the iterator to the first elements greater then a certain value

    binary_search       determines if an elements exists in a certain range

    equal_range         returns range of elements matching a specific key


Set operation ( or sorted range )

    merge               merges two sorted range

    inplace_merge       merges two ordered range in-place

    includes            return true if one set is a subset of another

    set_difference      computes the difference between two sets

    set_intersection    computes the intersection of two sets

    set_symmetric_difference        computes the symmetric difference between two sets

    set_union           computes the union of two sets


Heap Operation

    is_heap             checks if the given range is a max heap

    is_heap_until       finds the largest subrange that is a max heap

    make_heap           creates a max heap out of a range of elements

    push_heap           adds an elements to a max heap

    pop_heap            removes the largest elements form a max heap

    sort_heap           turns a max heap into a range of elements sorted in according order


Maximum / Minimum Operation

    max                 returns the greater of the given value

    max_element         returns the largest element in a range

    min                 returns the smaller of the given value

    min_element         returns the smallest element in a range

    minmax              returns the larger and the smaller of two elements

    minmax_element      returns the smallest and the largest elements in a range

    lexicographical_compare         returns true if one range is lexicographically less than another

    is_permutation      determines if a sequence is a permutation of another sequence

    next_permutation    generates the next larger lexicographic permutation of a range of elements

    prev_permutation    generates the next smaller lexicographic permutation of a range of elements


Numeric Operation

    iota                fills a range with successive increments of a string value

    accumulate          sums up a range of elements

    inner_product       computes the inner product of two range of elements

    adjacent_difference computes the difference between adjacent elements in a range

    partial_sum         computes the partial sum of a range of elements


C Library

    qsort               sorts a range of elements with unspecific type

    bserach             searches an array from an elements of unspecified type
