/*
Statements:
    01 Transactional memory
    02 Range-based for loop ( since c++ )

*/
/// 01 Transactional member is skipped because in the main site it is incomplete

/// 02 Range-based for loop, since c++11
// Executes a for loop over a range.
// Used as a more readable equivalent to the traditional for loop over a range
// of value, such as all element in a container.
// syntax:
// attribute (optional) for ( range_declaration : range_expression ) loop statement
// attribute (optional) => any number of attribute
// range_declaration    => a declaration of a named variable, whose type is the type
//                          of the element of the sequence represented by range_expression,
//                          or a reference to the type. Often uses the auto specifier for
//                          automatic type deduction.
// range_expression     => any expression the represents a suitable sequence (either an array
//                         an object for which 'begin' and 'end' member function or free function
//                         are defined) or a braced-init-list
// loop-statement       => any statement, typically a compound statement, which is the body of the loop.
//
//
// Notes:
// If the initializer ( range_expression ) is a braced-init-list, __range is deduced to be
// std::initializer_list<> &&.
// It is safe, and in face, preferable in generic code, to use deduction to forwarding reference
// for ( auto && var : sequence ).
//
//
//
// Example:

#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {0,1,2,3,4,5};
    for (const int &i : v )         // access by const reference
        std::cout<<i<<' ';
    std::cout<<std::endl;

    for (auto i : v)                // access by value, the type of 'i' is int
        std::cout<<i<<' ';
    std::cout<<std::endl;

    for (auto&& i : v)              // access by reference, the type if 'i' is int&
        std::cout<<i<<' ';
    std::cout<<std::endl;

    for ( int n : {0,1,2,3,4,5} )   // the initializer may be a braced-init-list
        std::cout<<n<<' ';
    std::cout<<std::endl;

    int arr[] = {0,1,2,3,4,5};
    for ( int n : arr )             // the initializer may be an array
        std::cout<<n<<' ';
    std::cout<<std::endl;
}
