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

Numeric Operation

    iota                fills a range with successive increments of a string value
    accumulate          sums up a range of elements
    inner_product       computes the inner product of two range of elements
    adjacent_difference computes the difference between adjacent elements in a range
    partial_sum         computes the partial sum of a range of elements

*/
/// iota ( meaning in Oxford: an exactly small amount )
/// example: There is not one iota of truth (= no truth at all) to the story
/// Also it is the ninth letter of the Greek alphabet
// Fills the range [first,last) with sequentially increasing values,
// starting with value ( the given value ) and repetitively evaluating ++value
// for example if the given value would be 0 the next is 1 then 2 like
// 0, 1, 2, 3, ... and so on


#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
#include <list>
#include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>


int main(){

    std::list<int> list(10);

    std::iota(list.begin(),list.end(),-4); // It is filled form -4 to 5

    typedef std::list<int>::iterator list_it;
    std::vector<list_it> vector(list.size());   // vector contains list of iterator
    std::iota(vector.begin(),vector.end(),list.begin()); // also form -4 to 5

    std::shuffle(vector.begin(),vector.end(),
                 std::mt19937{ std::random_device{}() } // only calls constructor ( constructor without object ) ( of course my opinion may be I am wrong )
                 );


    std::cout<<"The content of the list:\t";
    list_it beg = std::begin(list);
    list_it end = std::end(list);
    while(beg != end )std::cout<<*beg++<<' ';

    std::cout<<"\nThe content of the list, shuffled:\t";
    for(list_it it:vector) std::cout<<*it<<' ';
return 0;}









