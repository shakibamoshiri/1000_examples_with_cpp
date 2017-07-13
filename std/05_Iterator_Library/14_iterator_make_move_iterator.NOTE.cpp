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
/// std::make_move_iterator
// make_move_iterator is a convenience function template that constructs
// a std::move_iterator for the given iterator i with the type deduced form
// the type of the argument.

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

// just for fun :)
// Do not use in a real project.
template<typename C>
std::ostream& operator,(std::ostream& out, const C& obj){
    typedef typename C::const_iterator git;   // general iterator

    git first=std::begin(obj);
    git  last=std::end(obj);

    while(first!=last)out<<*first++<<' ';
    return out;
}

int main(){
    std::list<int> integer{1,2,3,4,5};
    std::cout<<"integer:\t",integer;   // just for fun :)

    std::vector<int> v1(integer.begin(),integer.end()); // copies from the integer
    std::cout<<"\nv1:\t",v1;

    std::vector<int> v2(std::make_move_iterator(integer.begin()),
                                std::make_move_iterator(integer.end()));    // moves the integer into the v2

    std::cout<<"\nv2:\t",v2;    // it has taken all of the element of integer

    /// Be careful that it does not work with int
    /// here the integer is still have its elements!
    std::cout<<"\ninteger:\t",integer;
    /// for more detail see:
    /*
    Why std::make_move_iterator works on vector<string> but not on vector<int>?

    http://stackoverflow.com/questions/25009351/why-stdmake-move-iterator-works-on-vectorstring-but-not-on-vectorint
    */

return 0;}
