/*
            Function Object
            ***************

5. some deprecated function since c++11
    5.1 base
        unary_function      adaptor-compatible unary function base class
        binary_function     adaptor-compatible binary function base class
    --------------------------------------------
    5.2 binders
        binder1st
        binder2nd           function object holding a binary function and one of its arguments
        bind1st
        bind2nd             binds one argument to a binary function
    --------------------------------------------
    5.3 Function adaptors
        pointer_to_binary_function      adaptor-compatible wrapper for a pointer to binary function
        ptr_fun                         creates an adaptor-compatible function object wrapper from a pointer to function
        mem_fun_t
        mem_fun1_t
        const_mem_fun_t
        const_mem_fun1_t                wrapper for a pointer to nullary or unary member function, callable with a pointer to object
        mem_fun                         creates a wrapper from a pointer to member function, callable with a pointer to object
        mem_fun_ref_t
        mem_fun1_ref_t
        const_mem_fun_ref_t
        const_mem_fun1_ref_t            wrapper for a pointer to nullary or unary member function, callable with a reference to object
        mem_fun_ref                     creates a wrapper from a pointer to member function, callable with a reference to object
*/
/// std::unary_function
//  It is a wrapper function object returning the complement
//  of the unary predicate it holds.

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>


struct less_than_7 : std::unary_function< int, bool > {
    bool operator() (int temp) const { return temp < 7; }
};

int main() {
    std::vector< int > vector;

    for( int index = 0; index < 10; vector.push_back( ++index ));   // filing the vector from 1 to 10
    for( const int i : vector) std::cout << i << ' ';

    std::unary_negate< less_than_7 > not_less_than_7(( less_than_7()));

    std::cout << std::count_if( vector.begin(), vector.end(), not_less_than_7); // 7 itself, 8, 9, and 10

    // so the output is 4
    //
    // vector holds: 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10
    //
    // less_than_7 are                 7, 8, 9, 10  that the function returns true
    // and for these:1, 2, 3, 4, 5, 6               that the function returns false




}


/* output for me:



*/


