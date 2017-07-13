/// Sequence containers : Array

/// 02_std::array::operator[] 'bracket'
/// definition in header < array >

/**
reference operator[] ( size_type pos );
const_reference operator[] ( size_type pos );
constexpr const_reference operator[] ( size_type pos ) const;

Returns a reference to the element at specified location POS.
No bounded checking is preformed.

NOTE : unlike std::map::operator[], this operator never insert
a new element into the containers.

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
        /// construction uses aggregate initialization
        std::array<const char*, 3> a1 { {"at pos one","at pos two","at pos three"} }; /// double-braces required in c++11 and not c++14
        for ( const char* s : a1 )
            std::cout<<s<<'|';
        std::cout<<"\na1.at[1] 'using operator[] to gets value : "<<std::endl;
        a1[1] = "changing the one element by operator[]";
        std::cout<<a1[1]<<std::endl;
    }

}
