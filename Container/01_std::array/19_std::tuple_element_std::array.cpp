/// Sequence containers : Array

/// 18_std::tuple_element( std::array)
/// definition in header < array >

/**
template < std::size_t I, class T, std::size_t N>
    struct tuple_element <I,array<T,N>>;

Provides compiles-time indexed access to the type of the elements
of the array using tuple-like interface

Possible Implementation:

template<std::size_t I, typename T>
    struct tuple_element;

template <std::size_t I, typename T, std::size_t N>
    struct tuple_element<I, std::array<T, N> >;

Return Value:

**/

#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <iterator>

//#include <unistd.h>

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        /// no sample
    }

}
