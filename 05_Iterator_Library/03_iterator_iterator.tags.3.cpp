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
// algorithm selection based on iterator category tags using std::enable_if

template<typename Condition,typename T=void>
using EnableIf_t=typename std::enable_if<Condition::value,T>::type;

template<typename Iterator,typename IteratorTag>
using is_same_iterator_condition=std::is_same<IteratorTag,typename std::iterator_traits<Iterator>::iterator_category>;

template<typename BDit, // bidirectional iterator
         typename = EnableIf_t<is_same_iterator_condition<BDit,std::bidirectional_iterator_tag>>>
         void alg(BDit,BDit){std::cout<<"alg() is called for BidirectionalIterator\n";}

template<typename RAit, // random access iterator
        typename = EnableIf_t<is_same_iterator_condition<RAit,std::random_access_iterator_tag>>,
        typename = void> // dummy value to avoid template re-definition errror
        void alg(RAit,RAit){std::cout<<"alg() is called for random_access_iterator\n";}

int main(){

    std::vector<int>vector;
    std::list<int>list;

    alg(vector.begin(),vector.end());   // calls random_access_iterator
    alg(list.begin(),list.end());       // calls bidirectional_iterator

return 0;}
