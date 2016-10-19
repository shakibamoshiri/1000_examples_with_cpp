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
/// partition copy
// Copies the elements from the range [first,last) in two different range
// depending on the value returned by predicate p.


#include <iostream>
#include <algorithm>
#include <iomanip>


#include <iterator>




// #include <random>
// #include <cstdlib>
// #include <ctime>



int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int less5[5]{0};
    int great5[5]{0};

    std::partition_copy(std::begin(arr),std::end(arr), // copies form this, to
                        std::begin(less5),             // less than 5 into this
                        std::begin(great5),            // greater then 5 into this
                        [](int i){return i<=5;});      // predicate by lambda expression
    std::cout<<"Less than 5, becomes:\t\t";
    for(int* i=less5; i!=std::end(less5);++i) std::cout<<*i<<' ';

    std::cout<<"\nGreater than 5, becomes:\t";
    for(int* i=great5; i!=std::end(great5);++i) std::cout<<*i<<' ';
    // or
    // for (auto it = std::begin(great5); it != std::end(great5); ++it)
    //      std::cout<<*it<<' ';
}










