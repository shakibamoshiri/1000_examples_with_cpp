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
/// back_inserter
// back_inserter is a convenience function template that constructs a
// std::back_insert_iterator for the container 'c' with the type deduced
// from the type of the argument.

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



/// would you like to obfuscate a code?

int main(){
    std::list
        <const char*>
            list{"how",
                "are","you",
                    "today?"};
                        std::fill_n
(std::back_inserter(list),3,"good");
std::cout<<list<<std::endl;return 0;}






