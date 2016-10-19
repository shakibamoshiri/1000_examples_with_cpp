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
/// upper_bound
// Returns an iterator pointing to the first element in the range [first,last)
// that is greater than value
// The range [first,last) must be partially sorted, i.e. partitioned with
// respect to the expression !(value < element) or !comp( value, element).
// A fully-sorted range meets this criterion, as does a range resulting
// from a call to std::partition
// The first version uses operator < to compare the elements, the second
// version uses the given comparison function comp.

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



int main(){
    typedef std::vector<int> vecInt;

    vecInt data ={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6};

    vecInt::iterator lower = std::lower_bound(data.begin(),data.end(),4);
    vecInt::iterator upper = std::upper_bound(data.begin(),data.end(),4);

    std::cout<<std::setw(20)<<std::left<<"length of bound:"<<upper-lower<<'\n';
    std::cout<<std::setw(20)<<std::left<<"result:";
    while( lower != upper )  std::cout<<*lower++<<' ';


}









