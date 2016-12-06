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
/// std::move_iterator
// std::move_iterator is an iterator adaptor which behaves exactly like the
// underlying iterator (which must be at least an InputIterator), except that
// dereferencing converts the value returned by the underlying iterator into
// a r-value. If this iterator is used as an input iterator, the effect is
// that the value are moved from, rather than copied from.


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

    std::vector<std::string> vs{"how","are","you","today?"};

    std::cout<<"Old contents of the vs:\t";
    for(std::string s:vs)std::cout<<s<<' ';

    typedef std::vector<std::string>::iterator itovos;  // iterator of vector of string
    std::string concat=std::accumulate(std::move_iterator<itovos>(vs.begin()),
                                       std::move_iterator<itovos>(vs.end()),
                                       std::string());  // empty string, Can be simplified with std:make_move_iterator

    std::cout<<"\nConcatenated as string:\t"
             <<concat
             <<"\nand new contents of the vs:\t";
             for(std::string s:vs)std::cout<<'"'<<s<<'"';

return 0;}
