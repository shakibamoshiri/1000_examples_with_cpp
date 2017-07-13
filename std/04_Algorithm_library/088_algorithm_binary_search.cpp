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
/// binary_search
// Checks if an elements equivalent to the value appears within the range [first,last).
// For std::binary_search to succeed, the the range [first, last) mush be at least partially sorted
// i.e. it must satisfy all of the following requirement:
// > partitioned with respect to element < value or comp(element, value)
// > partitioned with respect to !(value < element) or !comp(element, value)
// > For all elements, if element < value or comp(element, value) is true then
//   ! (value < element) or comp(value, element) is also true.



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

    vecInt haystack{1,3,4,5,6};
    vecInt needles{1,2,3};

    for(const int f:needles){

        //std::cout<<"Searching for "<<f<<'\n';
        // if found, print a '+' before found value ( print +f)
        // else print value                         ( print f )
        if( std::binary_search(haystack.begin(),haystack.end(),f) ) std::cout<<'+'<<f<<' ';
        else                                                        std::cout<<f<<' ';

    }
}









