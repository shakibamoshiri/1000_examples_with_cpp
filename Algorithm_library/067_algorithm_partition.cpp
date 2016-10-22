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

Partitioning Operation

    is_partitioned      determines if the range is partitioned by the give predicate
    partition           divides a range of elements into two groups
    partition_copy      copies a range dividing the elements into two groups
    stable_partition    divides elements into two groups while preserving their relative order
    partition_point     locates the partition point of a partitioned range
*/
/// partition
// Reorders the element in the range [firs,last) in such a way that all
// elements for which the predicate p returns true precede the elements
// for which predicate p returns false.
// Relative order of the elements is not preserved.



#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>

#include <iterator>
#include <vector>
#include <array>
#include <forward_list>

// #include <random>
// #include <cstdlib>
// #include <ctime>


template<class FwIt>
void
quicksort (FwIt first, FwIt last){
    if(first==last) return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    FwIt mid1 = std::partition(first,   // beginning of the container
                               last,   // end of the container
                               [pivot](const auto& em){return em<pivot;}); // lambda expression ( predicate )
    FwIt mid2 = std::partition(mid1,
                               last,
                               [pivot](const auto& em){return !(pivot<em);});
    quicksort(first,mid1);
    quicksort(mid2,last);
}

int main(){
    std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
    std::cout<<"original v:\t";     for(const int i:v)std::cout<<i<<' ';

    auto it = std::partition(v.begin(),v.end(),[](int i){return i%2==0;});

    std::cout<<"\npartitioned v:\t";  for_each(v.begin(),it,[](int i){std::cout<<i<<' ';});
    // or using std::copy
    // std::copy(std::being(v), it, std::ostream_iterator<int>(std::cout," "));
    std::cout<<'*';
    std::copy(it, std::end(v),std::ostream_iterator<int>(std::cout," "));

    std::forward_list<int> fl{1,332,3,-1,44,5,-5,-55,9,0,11,4,5878,34};
    std::cout<<"\nunsorted list:\t";    for(const int i:fl)std::cout<<i<<' ';

    // using quicksort
    quicksort(fl.begin(),fl.end());
    std::copy(std::begin(fl),std::end(fl),std::ostream_iterator<int>(std::cout<<"\nsorted using quicksrot:\t"," "));


}










