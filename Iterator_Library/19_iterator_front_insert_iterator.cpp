/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
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
/// front_insert_inserter
// std::front_insert_iterator is an OutputIterator that prepared elements
// to a container for which it was constructed. The container's push_front()
//member is called whenever the iterator (whether dereferenced or not) is
// assigned to.
// Incrementing the std::front_insert_iterator is a no-op

#include <iostream>
#include <iterator>

#include <algorithm>
// #include <functional> // std::greater<int>()
 // #include <vector>
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


#include "print_container" // operator<< overloaded





int main(){
    std::list<int> list(5,1); // it has: 1,1,1,1,1

    std::fill_n(std::front_insert_iterator<std::list<int>>(list),   // output
                5,                                                  // size
                -1);                                                // data for push_front()

    std::cout<<list<<std::endl; // -1,-1,-1,-1,-1,1,1,1,1,1
return 0;}






