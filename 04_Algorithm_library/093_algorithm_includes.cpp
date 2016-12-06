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

Set operation ( or sorted range )

    merge               merges two sorted range
    inplace_merge       merges two ordered range in-place
    includes            return true if one set is a subset of another
    set_difference      computes the difference between two sets
    set_intersection    computes the intersection of two sets
    set_symmetric_difference        computes the symmetric difference between two sets
    set_union           computes the union of two sets

*/
/// include
// Return true if every element from the sorted range [first2,last2)
// is found within the sorted range [first,last). Also return true if
// [first2,last2) is empty.
// The first version expects both ranges to be sorted with operator <,
// and the second version expects them to be sorted with the given
// comparison function comp.

#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>
#include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
#include <random>
// #include <cstdlib>
// #include <ctime>



int main(){

    std::vector<char> v1 {'a','b','c','f','h','x'};
    std::vector<char> v2 {'a','b','c'};
    std::vector<char> v3 {'a','c'};
    std::vector<char> v4 {'g'};
    std::vector<char> v5 {'a','c','b'};

    for(const char c:v1) std::cout<<c<<' ';

    std::cout<<"\n\nIncludes:\n"<<std::boolalpha;
    for(const char c:v2) std::cout<<c<<' ';
    std::cout<<std::setw(20)<<std::left<<std::includes(v1.begin(),v1.end(),v2.begin(),v2.end())<<'\n';
    for(const char c:v3) std::cout<<c<<' ';
    std::cout<<std::setw(20)<<std::left<<std::includes(v1.begin(),v1.end(),v3.begin(),v3.end())<<'\n';
    for(const char c:v4) std::cout<<c<<' ';
    std::cout<<std::setw(20)<<std::left<<std::includes(v1.begin(),v1.end(),v4.begin(),v4.end())<<'\n';
    for(const char c:v5) std::cout<<c<<' ';
    std::cout<<std::setw(20)<<std::left<<std::includes(v1.begin(),v1.end(),v5.begin(),v5.end())<<'\n';

    auto cmp_noCase0 = [](char a,char b){return std::tolower(a)<std::tolower(b);};
    // or you can use
    bool (*cmp_noCase1)(char,char) = [](char a,char b){return std::tolower(a)<std::tolower(b);};

    std::vector<char> v6{'A','B','C'};
    std::cout<<"com_noCase:\n";
    for(const char c:v6) std::cout<<c<<' ';
    std::cout<<std::setw(20)<<std::left<<std::includes(v1.begin(),v1.end(),v6.begin(),v6.end(),cmp_noCase1)<<'\n';
}







