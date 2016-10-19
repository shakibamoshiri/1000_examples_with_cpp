/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.
------------------------------------------------------------------
You can read the original implementation in:
stl_algobase.h and stl_algo.h and algorithmfwd.h
------------------------------------------------------------------
Defined in header <algorithm>

Modifying sequence operation
    copy
    copy_if             copies a range of elements to a new location
    copy_n              copies a number of elements to a new location
    copy_backward       copies a range of elements in backward order
    move                moves a range of elements to a new location
    move_backward       moves a range of elements to a new location in backward order
    fill                assigns a range of elements a certain value
    fill_n              assigns a value to a number of elements
    transform           applies a function to a range of elements
    generate            saves the result of a function in a range
    generate_n          saves the result of N applications of a function
    remove
    remove_if           removes elements satisfying specific criteria
    remove_copy
    remove_copy_if      copies a range of elements omitting those that satisfy specific criteria
    replace
    replace_if          replaces all value satisfying specific criteria with another value
    replace_copy
    replace_copy_if     copies a range, replacing elements satisfying specific criteria with another value

    swap                swaps the value of two objects
    swap_range          swaps the two range of elements
    iter_swap           swaps the elements pointed to by two iterator

    reverse             reverses the order of elements in a ragne
    reverse_copy        creates a copy of a range that is reversed
    rotate              rotate the order of elements in a range
    rotate_copy         copies and rotate a range of elements
    shuffle
    random_shuffle      randomly re-orders elements in a range
    (until c++ 17)(c++11)
    unique              removes consecutive duplicate element in a range
    unique_copy         creates a copy a of some range of elements that contains no consecutive duplicate
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <array>


/// swap                swaps the value of two objects
// Exchanges the given values
// One version, swaps the value a and b
// and the other version swaps the arrays a and b in effect call std::swap_ranges(a, a+N, b).

int main(){
    int a = 5, b = 3;

    // before
    std::cout<<a<<' '<<b<<std::endl;

    std::swap(a,b);

    // after
    std::cout<<a<<' '<<b<<std::endl;
}


/*
The following overloads are already provided by the standard library

std::swap(std::pair)
(C++11)
std::swap(std::tuple)
(C++11)
std::swap(std::shared_ptr)
(C++11)
std::swap(std::weak_ptr)
(C++11)
std::swap(std::unique_ptr)
(C++11)
std::swap(std::function)
(C++11)
std::swap(std::basic_string)
std::swap(std::array)
(C++11)
std::swap(std::deque)
std::swap(std::forward_list)
(C++11)
std::swap(std::list)
std::swap(std::vector)
std::swap(std::map)
std::swap(std::multimap)
std::swap(std::set)
std::swap(std::multiset)
std::swap(std::unordered_map)
(C++11)
std::swap(std::unordered_multimap)
(C++11)
std::swap(std::unordered_set)
(C++11)
std::swap(std::unordered_multiset)
(C++11)
std::swap(std::queue)
std::swap(std::priority_queue)
std::swap(std::stack)
std::swap(std::valarray)
(C++11)
std::swap(std::basic_stringbuf)
(C++11)
std::swap(std::basic_istringstream)
(C++11)
std::swap(std::basic_ostringstream)
(C++11)
std::swap(std::basic_stringstream)
(C++11)
std::swap(std::basic_filebuf)
(C++11)
std::swap(std::basic_ifstream)
(C++11)
std::swap(std::basic_ofstream)
(C++11)
std::swap(std::basic_fstream)
(C++11)
std::swap(std::basic_regex)
(C++11)
std::swap(std::match_results)
(C++11)
std::swap(std::thread)
(C++11)
std::swap(std::unique_lock)
(C++11)
std::swap(std::promise)
(C++11)
std::swap(std::packaged_task)
(C++11)
*/
