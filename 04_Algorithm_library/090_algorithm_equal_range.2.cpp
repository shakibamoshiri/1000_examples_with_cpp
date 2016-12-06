/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.
------------------------------------------------------------------
You can read the original implementation in:
stl_algobase.h and stl_algo.h and algorithmfwd.h
------------------------------------------------------------------
Defined in header <algorithm>

Binary Search operation ( on sorted range )

    lower_bound         returns the iterator to the first elements not less then the given value
    upper_bound         returns the iterator to the first elements greater then a certain value
    binary_search       determines if an elements exists in a certain range
    equal_range         returns range of elements matching a specific key
*/
/// equal_range
// Returns a range containing all elements equivalent to value [first,last).
// The range [first,last) must be partitioned with respect to comparison with value,
// i.e. must satisfy all of the following requirement:
// > partitioned with respect to element < value or comp(element, value)
// > partitioned with respect to !(value < element) or !comp(element, value)
// > For all elements, if element < value or comp(element, value) is true then
//   ! (value < element) or comp(value, element) is also true.
//
// A fully-sorted range must these criteria, as does a range resulting from a call to std::partition.
// The returned range is defined by two iterator, one pointing to the first element
// that is not less that value and another pointing to the first element greater
// than value.
// The first iterator may by alternatively obtained with std::lower_bound(),
// the second -- with std::upper_bound().
//
// The first version uses operator < to compare,
// and the second version uses given comparison function.



#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
#include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
// #include <random>
// #include <cstdlib>
// #include <ctime>

struct S {
    int number;
    char name;
    S(int n, char c): number(n), name(c){}

    // only the number is relevant with this comparison
    bool operator<(const S& tmp)const{ return number < tmp.number; }
};

/// example with comparator
struct Comp {
    bool operator()(const S& s, int i) {return s.number < i;}
    bool operator()(int i, const S& s) {return i < s.number;}
};


int main(){
    // note: not ordered, only partitioned w.r.t. S defined below
    std::vector<S> vec={ {1,'A'},{2,'B'},{2,'C'},{2,'D'},{4,'G'},{3,'F'} };

    S value{2,'?'};
    std::vector<S>::iterator fir;
    std::vector<S>::iterator sec;

    // return std::pair containing a pair of iterators defining the wanted range,
    // the first pointing to the first element that is not less than value and
    // the second pointing to the first element greater that value.
    //
    // If there are no elements not less than value, last is returned as the first element.
    // Similarly if there are no element greater than value, last is returned as the second element.

    // using struct Comp for comparison
    auto p = std::equal_range(vec.begin(), vec.end(), 2, Comp());

    for(auto  i=p.first; i!=p.second; ++i) std::cout<<i->name<<' ';
}







