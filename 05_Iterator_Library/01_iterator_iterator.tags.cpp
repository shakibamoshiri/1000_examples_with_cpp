/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
    type_traits
-------------------------------------------------
Marking input iterators.
struct input_iterator_tag { };

Marking output iterators.
struct output_iterator_tag { };

Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag { };

Bidirectional iterators support a superset of forward iterator operations.
struct bidirectional_iterator_tag : public forward_iterator_tag { };

Random-access iterators support a superset of bidirectional iterator operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

Defined the category of iterator.
Each tag is an empty type and corresponds to one of the five iterator category:
    - input_iterator_tag            corresponds to      InputIterator
    - output_iterator_tag           corresponds to      OutputIterator
    - forward_iterator_tag          corresponds to      ForwardIterator
    - bidirectional_iterator_tag    corresponds to      BidirectionalIterator
    - random_iterator_tag           corresponds to      RandomAccessIterator
    - NOTE: there is no separate tag for ContiguousIterator


Iterator category tags carry information that can be used to select the most
efficient algorithm for the specific requirement set that is implied by the category.
For every iterator type, a typedef std::iterator_traits<Iterator>::iterator_category
is available, which is an alias to out of these five tag types
*/


#include <iostream>
#include <iterator>



// #include <algorithm>
// #include <functional> // std::greater<int>()
 #include <vector>
 #include <list>
// #include <set>
// #include <string>

// #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>
// #include <climits>

/// example:
// Common technique for algorithm selection based on iterator category
// tags is to use a dispatcher function (the alternative is std::enable_if)

template<class BDiter>
void alg(BDiter,BDiter,std::bidirectional_iterator_tag){
    std::cout<<"alg() called for bidirectional iterator\n";
}


template<class RAiter>
void alg(RAiter,RAiter,std::random_access_iterator_tag){
    std::cout<<"alg() called for random access iterator\n";
}

template<class Iter>
void alg(Iter first, Iter last){
    alg(first,last,
        typename std::iterator_traits<Iter>::iterator_category());
}


int main(){
    std::vector<int> vector;
    alg(vector.begin(),vector.end());   // calls random access

    std::list<int> list;
    alg(list.begin(),list.end());       // calls bidirectional

return 0;}
