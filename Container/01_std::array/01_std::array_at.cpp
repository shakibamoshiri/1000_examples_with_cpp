/// Sequence containers : Array

/// 01_std::array::at
/// definition in header < array >

/**
reference at ( size_type pos ); since c++11
const_reference at (size_type pos ) const; since c++11
constexpr const_reference at ( size_type pos ) const; since c++14

Returns a reference to element at specified location POS, with bounds
checking. if POS within the range of the container, an exception of
std::out_of_range is thrown

Return Value:
Reference to the request element
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
        /// construction uses aggregate initialization
        std::array<const char*, 3> a1 { {"at pos one","at pos two","at pos three"} }; /// double-braces required in c++11 and not c++14
        for ( const char* s : a1 )
            std::cout<<s<<'|';
        std::cout<<"a1.at(1) : "<<std::endl;

        std::cout<<a1.at(1)<<std::endl;
    }

}
