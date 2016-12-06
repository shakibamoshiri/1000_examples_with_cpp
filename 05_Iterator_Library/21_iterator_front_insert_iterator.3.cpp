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
    std::list<int> list;
    std::vector<int> vector{1,2,3,4,5};

    std::copy(vector.begin(),vector.end(),
              std::front_insert_iterator<std::list<int>>(list)); // push all vector member in front of the list member

    std::cout<<list<<std::endl;
    // output: 5 4 3 2 1
    // It look like a reverse order
    // because:
    // first push 1
    // then push 2 before 1
    // then push 3 before 2
    // then push 4 before 3
    // finally push 5 before 4
    // and the result will 5 4 3 3 2 1
return 0;}






