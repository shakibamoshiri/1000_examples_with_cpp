/// Sequence containers : Array

/// 16_std::get( std::array )
/// definition in header < array >

/**
template< size_t I,class T,size_t N>
    constexpr T& get ( array<T, N>& a);

template< size_t I,class T,size_t N>
    constexpr T&& get ( array<T, N>&& a);

template< size_t I,class T,size_t N>
constexpr const T&& get ( const array<T, N>&& a);

template< size_t I,class T,size_t N>
constexpr const T&& get ( const array<T, N>&& a);

Extract the Ith element form the array.
'I' must be an integer value in range [ 0, N ). This is
enforced at compile time as opposed to at() or operator[]

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
        /// filling with const char*
        std::array<const char*, 3> name;
        std::get<0>(name) = "Some cunt";
        std::get<1>(name) = "Nasim cunt";
        std::get<2>(name) = "Hajar cunt";

        for ( const char * s : name )
            std::cout<<s<<std::endl;

        std::cout<<"\nWith using std::get: ";
        std::cout<<std::get<0>(name)<<std::endl;
    }

}
