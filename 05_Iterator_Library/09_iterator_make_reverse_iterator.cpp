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
/// std::make_reverse_iterator
// make_reverse_iterator is a convenience function template that
// constructs a std::reverse_iterator for the given iterator i
// with the type deduced from the type of the argument.




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

    std::vector<float> vfloat{1.1,2.2,3.3,4.4,5.5};

    std::copy(std::begin(vfloat),std::end(vfloat),                                  // from
              std::ostream_iterator<float>(std::cout<<"Common iterator:\t"," "));   // to

    std::copy(std::make_reverse_iterator(vfloat.end()),     // makes vfloat to r_end
              std::make_reverse_iterator(vfloat.begin()),   // makes vfloat to r_begin()
              std::ostream_iterator<float>(std::cout<<"\nstd::make_reverse_iterator:\t"," "));



return 0;}
