/// Sequence containers : Array

/// 08_std::array::rbegin_crbegin
/// definition in header < array >

/**
revers_iterator rbegin();
const_revers_iterator rbegin() const;
const_revers_iterator crbegin() const;

Returns a revers iterator to the first element of the reserved container.
It corresponds to the last element of the non-reserved.

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
        std::array<const char*, 3> chs = {"shakib", "omid", "farshid"};
        std::cout<<"array with 'rbegin ': "<<*chs.rbegin()<<std::endl; /// print : farshid
        std::cout<<"array with 'crbegom': "<<*chs.crbegin()<<std::endl; /// print : farshid


    }

}
