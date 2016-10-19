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

Sorting Operation

    is_sorted           checks whether a range is sorted into according order
    is_sorted_until     finds the largest sorted subrange
    sort                sorts a range into according order
    partial_sort        sorts the first N elements of a range
    partial_sort_copy   copies and partially sort a range of elements
    stable_sort         sorts a range of elements while preserving order between equal elements
    nth_elements        partially sorts the given range making sure that it is partitioned by the given elements

*/
/// sort
// Sorts the elements in the range [first,last) in ascending order ( it mean 1,2,3,...)
// The order of equal elements is not guaranteed to be preserved.
// The first version uses operator < to compare the elements, the second
// version uses the given comparison function object comp.



#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>

#include <array>
 #include <random>
 // #include <cstdlib>
 // #include <ctime>




int main(){
    std::srand(std::time(0));

    std::random_device rd;
    std::mt19937 g(rd());

    std::array<int,10> arr{0};

    auto itArrBeg = std::begin(arr);

    // fill the arr with the random number
    while( itArrBeg != std::end(arr) ) *itArrBeg++ = ( g()%10);

    itArrBeg-=10; // put the pinter back to the beginning of the arr by -=10
    std::cout<<"arr:\t";    while( itArrBeg != std::end(arr) ) std::cout<<*itArrBeg++<<' ';

    // sort using the default operator <
    std::sort(std::begin(arr), std::end(arr));
    itArrBeg-=10;   std::cout<<"\narr:\t";    while( itArrBeg != std::end(arr) ) std::cout<<*itArrBeg++<<' ';

    // sort using a standard library compare function object
    std::sort(std::begin(arr), std::end(arr), std::greater<int>());
    itArrBeg-=10;   std::cout<<"\narr:\t";    while( itArrBeg != std::end(arr) ) std::cout<<*itArrBeg++<<' ';

    // sort using a custom function
    struct{ bool operator()(int a,int b){return a < b;}}customLess; // overload operator () for using form the object customLess
    std::sort(std::begin(arr),std::end(arr),customLess);
    itArrBeg-=10;   std::cout<<"\narr:\t";    while( itArrBeg != std::end(arr) ) std::cout<<*itArrBeg++<<' ';

    // sort using the lambda expression
    std::sort(std::begin(arr), std::end(arr),[](int a, int b){ return a > b; });
    itArrBeg-=10;   std::cout<<"\narr:\t";    while( itArrBeg != std::end(arr) ) std::cout<<*itArrBeg++<<' ';
}

