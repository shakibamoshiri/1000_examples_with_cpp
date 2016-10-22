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
*/

/// You can read the original implementation in:
/// stl_algobase.h and stl_algo.h


#include <iostream>
#include <algorithm>

/// std::for_each
// Applies the given function iterator, f may modify the elements of the range
// through the dereferenced iterator if f return a result, the result is ignored.
//
// Possible implementation
template<class InputIt, class UnaryFunction>
UnaryFunction for_each (InputIt first, InputIt last, UnaryFunction f){
    for(; first != last; ++first){
        f(*first);
    }
}

// example
// The following example uses the lambda function to increment all of the element
// of a vector and then uses and overloaded operator() in a function to compute
// their sum

#include <vector>

struct Sum {
    int sum;

    Sum(){ sum = 0; }
    void operator()(int t){ sum+=t; }
};


int main(){

    std::vector<int> num{3,4,2,9,15,267};
    std::cout<<"before ";
    for ( int t : num )
        std::cout<<' '<<t;


    // for_each does ++t on each element of num
    std::for_each(num.begin(), num.end(), [](int &t){ ++t;});


    std::cout<<"\nAfter for_each ";
    for(int t : num )
        std::cout<<' '<<t;

    // calls Sum::operator) for each number
    Sum s = std::for_each(num.begin(), num.end(), Sum());

    std::cout<<"\nSum of the num is "
             <<s.sum;

    // Does for_each with range-base-for
    std::cout<<"\nUsing range-base-for, instead of for_each ";
    for( int& t : num )
        ++t;

    for (int t : num )
        std::cout<<' '<<t;
}
