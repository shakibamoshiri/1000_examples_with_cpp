/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.

Defined in header <algorithm>

Non-modifying sequence operation
    all_of
    any_of
    noun_of             check, if the predicate is true for all, any, or none of the element is a range
    for_each            applies a function to a range of element
    count
    count_if            return the number of elements satisfying specific criteria
    mismatch            find the first position, where to ranges differ
    equal               determines if two set of elements are the same

    find
    find_if
    find_if_not         find the first element satisfying specific criteria
    find_end            find the last sequence of elements in certain range
    find_first_of       search for any one of a set of elements
    adjacent_find       find the first two adjacent items that are equal (or satisfy a given predicate)
    search              searches for a range of elements
    search_n            search for a number consecutive copies of an element in a range.
*/
/// You can read the original implementation in:
/// stl_algobase.h and stl_algo.h




/// std::find, std::find_if, and std::find_if_not(c++11)
//
// std::find:       searches for an elements equal to value
// std::find_if     searches for an elements for which predicate p return true
// std::find_if_not searches for an elements for which predicate p return false



#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


/// my example, not form the en.cpp...

int main(){

    std::vector<std::string> she{"hello","how","are","you","today?"};
    for(std::string  t : she )
        std::cout<<'['<<t<<']'<<' ';

    std::cout<<std::endl;
    // This is a wrong syntax
    // because at the beginning when it is compared "hello" with "are" , the if statement false,
    // but the lambda expression return true, why? I do not know
    std::vector<std::string>::iterator it1 = std::find_if(she.begin(),she.end(),[](const std::string cs){ if (cs == "are") return true; });
    std::cout<<*it1<<std::endl;

    // but this syntax is true, with second return
    std::vector<std::string>::iterator it2 = std::find_if(she.begin(),she.end(),[](const std::string cs){ if (cs == "are") return true;return false; });
    std::cout<<*it2<<std::endl;

    // the easies way may by is:
    // okay when cs was equaled with "are"
    // the function return true
    std::vector<std::string>::iterator it3 = std::find_if(she.begin(),she.end(),[](const std::string cs){ return cs == "are"; });
    std::cout<<*it3<<std::endl;



}
/*
error: could not convert ‘std::find_if<__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char>*,
std::vector<std::__cxx11::basic_string<char> > >, main()::<lambda(std::__cxx11::string)> >
(she.std::vector<_Tp, _Alloc>::begin<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >(),
  she.std::vector<_Tp, _Alloc>::end<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >(),
 (<lambda closure object>main()::<lambda(std::__cxx11::string)>{}, main()::<lambda(std::__cxx11::string)>()))’
 from ‘__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char>*, std::vector<std::__cxx11::basic_string<char> > >’ to ‘bool’|


*/

