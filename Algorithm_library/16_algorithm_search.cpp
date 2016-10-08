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
/// stl_algobase.h and stl_algo.h and algorithmfwd.h

#include <iostream>
#include <algorithm>
#include <vector>
// #include <iterator>




/// search          searches for a range of elements
// Searches for the first occurrence of the subsequence of elements
// (s_first,s_last] in the range (first, last] - (s_last, s_fist)).
//
// return value:
// An iterator to the beginning of the first subsequence

template<typename Container>
bool in_quote(const Container& cont, const std::string& s){
    return std::search(cont.begin(), cont.end(),s.begin(),s.end()) != cont.end();
}

int main(){
    std::string str ("why waste time learning, when ignorance is instantaneous?");

    // str.find can be use as well
    std::size_t sz = str.find("time");
    for(;sz < str.size();sz++)
        std::cout<<str[sz];

    std::boolalpha(std::cout);
    std::cout<<"\nIs \"time\" word in the str? "<<in_quote(str, "time")<<std::endl;
    std::cout<<"\nIs \"IS\" word in the str? "<<in_quote(str, "IS")<<std::endl;

    std::vector<char> vt(str.begin(),str.end());
    std::cout<<"\nIs \"time\" word in the vt? "<<in_quote(vt, "time")<<std::endl;
    std::cout<<"\nIs \"IS\" word in the vt? "<<in_quote(vt, "IS")<<std::endl;


}

