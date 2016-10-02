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
#include <iostream>
#include <algorithm>


// Defined in header algorithm
// Possible implementation
/// std::all_of
// Returns true if unary predicate returns true for all elements in the range,
// false otherwise. Returns true if the range is empty
template<class InputIt, class UnaryPredicate>
bool all_of (InputIt first, InputIt last, UnaryPredicate p){
    return std::find_if_not(first, last, p) == last;
}

/// std::any_of
// Returns true if unary predicate returns true at least one element in the range,
// false otherwise. Returns false if the range is empty
template<class InputIt, class UnaryPredicate>
bool any_of ( InputIt first, InputIt last, UnaryPredicate p){
    return std::find_if (first, last, p) != last;
}

/// std::none_of
// Returns true if unary predicate returns true for no elements in the range,
// false otherwise. Returns true if the range is empty
template<class InputIt, class UnaryPredicate>
bool none_of (InputIt first, InputIt last, UnaryPredicate p){
    return std::find_if(first, last, p) == last;
}

#include <numeric>
#include <iterator>
#include <functional>
#include <vector>
#include <iomanip>


int main(){
    const int sz=25;    // assigns to std::setw()
    std::vector<int> v(10,2);
    std::cout<<std::setw(sz)<<std::left<<"v has : ";
    for ( int t : v )
        std::cout<<t<<' ';
    std::cout<<std::endl;

    std::partial_sum(v.cbegin(),v.cend(),v.begin());
    std::cout<<std::setw(sz)<<std::left<<"Among the number: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;

    if(std::all_of(v.cbegin(),v.cend(),[](int i){return i%2 == 0;})){
        std::cout<<std::setw(sz)<<"All numbers are even"<<std::endl;
        // if you instead of std::endl, you use the "\n", the extra setw does not
        // extract form the buffer, so it fill the new line
        // test this std::endl with "\n", so that you can see what happens
        // for the next line
    }
    if(std::none_of(v.cbegin(), v.cend(), std::bind(std::modulus<int>(), std::placeholders::_1, 2))){
        std::cout<<std::setw(sz)<<std::left<<"None of them are odd"<<std::endl;
    }


    struct DivisibleBy {
        const int d;
        DivisibleBy(int n): d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };

    // DivisibleBy works like a lambda expression
    // Instead of that we can use
    // [](int i){ return i % 7 == 0; }
    if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7) )){
        std::cout<<"At least one number is divisible by 7"<<std::endl;
    }

}
