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
/// partition point
// Examines the partitioned ( as if by std::partition ) range [first,last)
// and locates the end of the first partition, that is the elements that
// does not satisfy p or last if all elements satisfy p.


#include <iostream>
#include <algorithm>
#include <iomanip>


#include <iterator>




// #include <random>
// #include <cstdlib>
// #include <ctime>



int main(){
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};

    bool (*_even)(int) = [](int i){return i%2==0;};
    // dividing into two partition
    std::partition(v.begin(),v.end(),_even);



    // so we can find the locate of the two part of v container
    // by using std::partition_point that return the iterator
    // past the of the first partition within [first,last) or last if all elements satisfy predicate p
    std::vector<int>::iterator itbet = std::partition_point(v.begin(),v.end(),
                         // needs the same predicate the is used before
                         _even);



    for_each(v.begin(),itbet,[](int i){std::cout<<i<<' ';});
    std::cout<<'\n';
    for_each(itbet,v.end(),[](int i){std::cout<<i<<' ';});
    return 0;

}










