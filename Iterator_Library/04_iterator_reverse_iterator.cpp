/*
            The Iterator Library
            ********************
For more detail you can see:
    std_iterator_base_types.h
    type_traits
-------------------------------------------------
Iterator adaptors
    reverse iterator:               iterator adaptors for reverse-order traversal
    make_reverse_iterator:          creates a std::reverse_iterator of type inferred form the argument
    move_iterator:                  iterator adaptor which dereferences to an r-value reference
    make_move_iterator:             creates a std::move_iterator of type inferred ( deduced ) from the argument
    back_insert_iterator:           iterator adaptor for insertion at the end of a container
    back_inserter:                  creates a std::back_insert_iterator of type inferred from the argument
    front_insert_iterator:          iterator adaptor for insertion at the front of a container
    front_inserter:                 creates a std::front_insert_iterator of type inferred form the argument
    insert_iterator:                iterator adaptor for insertion into a container
    inserter:                       create a std::insert_iterator of type inferred form the argument

*/
/// std::reverse_iterator
// std::reverse_iterator is an iterator adaptor that reverse the direction
// of a given iterator. In other words, when provided with a bidirectional
// iterator, std::reverse_iterator produced a new iterator that moves form
// the end to the beginning of the sequence defined by the underlying
// bidirectional iterator.
//
// For a reverse iterator r constructed from an iterator i, the relationship
// &*r == &*(i-1) is always true (as long as r is dereferenceable); thus a
// reverse iterator constructed form a one-past-the-end iterator dereference
// to the last element is a sequence.
//
// re:  reverse_end (past-the-last element)
// rb:  reverse_beginning
// -----------------------------------------------------------------
// | re|   |   |   |   |   |   |   |   |   |   |   |   |   |   |rb |
// -----------------------------------------------------------------
//
/// Reverse iterator stores an iterator to the next element than
/// the one it actually refers to
//
// b:   beginning
// e:   end ( past-the-end element)
// -----------------------------------------------------------------
// | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   | e |
// -----------------------------------------------------------------




#include <iostream>
#include <iterator>

#include <algorithm>
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


int main(){

    std::vector<int>vector(10,0);
    std::iota(vector.begin(),vector.end(),1);//filling vector with 1,2,3,4,5...

    std::reverse_iterator<std::vector<int>::iterator>ritv=vector.rbegin();// it is '10'

    *ritv=1000;      // modifies 10 to 1000

    std::cout<<"vector after *ritv=1000:\t";
    for(const int i:vector)std::cout<<i<<' ';

    ritv[0]=-1;     // [0]=10, [1]=9, [2]=8, ... and so forth
    // note:
    // ritv[9] point to 1 not to 10

    std::cout<<"\nvector after ritv[9]=-1:\t";
    for(const int i:vector)std::cout<<i<<' ';



return 0;}

