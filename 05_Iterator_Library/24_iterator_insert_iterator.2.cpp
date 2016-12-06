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
/// insert_iterator
// std::insert_iterator is an OutputIterator that inserts elements into a
// container for which it was constructed, at the position pointed to by
// supplied iterator. The container's insert() member function is called
// whenever the iterator ( whether dereferenced or not) is assigned to.
// Incrementing the std::insert_iterator is a no-op


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


#include "print_container" // operator<< overloaded



int main(){
    std::list<int> list{6,6,6};
    std::vector<int> vector{1,2,3,4,5};

    std::copy(list.begin(),list.end(),
              std::insert_iterator<std::vector<int>>(vector,vector.begin()+1)); // vector: 1, 6,6,6, 2,3,4,5

    std::cout<<vector<<std::endl;

return 0;}






