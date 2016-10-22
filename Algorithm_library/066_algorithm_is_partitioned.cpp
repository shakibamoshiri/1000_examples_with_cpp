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

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>

#include <iterator>
#include <vector>
#include <array>

// #include <random>
// #include <cstdlib>
// #include <ctime>

template<typename W, typename T> void print (const char* name,T type){
    const int L=strlen(name);
    std::cout<<std::setw(L+10)<<std::left<<name;
    for(W t : type) std::cout<<t<<' ';
}


/// is_partitioned      determines if the range is partitioned by the give predicate
// Returns true if all elements in the range [first, last) that satisfy the predicate
// p appear before all elements that do not.
// Also returns true if [first,last) is empty.

int main(){
    std::array<int,10> arr{0,1,2,3,4,5,6,7,8,9};
    print<int>("arr:",arr);

    auto is_even =  [](int i){return i%2==0;};
    // or
    bool (*is_even2)(int) = [](int i){return i%2==0;};

    std::cout.setf(std::ios_base::boolalpha);

    // testing for if arr is partitioned
    std::cout<<"\nIs_partitioned(arr):\t";
    std::cout<<std::is_partitioned(arr.begin(),arr.end(),is_even);

    // makes arr partition
    std::partition(arr.begin(),arr.end(),is_even2);
    std::cout<<"\nPartitioned(arr):\n";
    print<int>("arr:",arr);
    std::cout<<"\nIs_partitioned(arr):\t";
    // testing again if arr is partitioned
    std::cout<<std::is_partitioned(arr.begin(),arr.end(),is_even);

    std::reverse(arr.begin(),arr.end());
    std::cout<<"\nIs_partitioned(arr):\t";
    std::cout<<std::is_partitioned(arr.begin(),arr.end(),is_even);



}













