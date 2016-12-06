/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack

    09 sizeof ... operator

    10 fold expression
    11 dependent names
    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>
#include <array>
template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };

/// 09 sizeof ... operator
// Queries the number of elements in a parameter pack.
// syntax:
// sizeof... ( parameter pack )
// Return a constant of type size_t

/// Example
template<typename... Ts> constexpr auto make_array(Ts&&... ts)
    -> std::array< std::common_type_t<Ts...>, sizeof...(ts)>
    {
        return { std::forward<Ts>(ts)... };
    }

int main() {
    auto b = make_array(1,2,3);
    std::cout<<b.size()<<std::endl;
    for ( auto i : b )
        std::cout<<i<< ' ';

}
