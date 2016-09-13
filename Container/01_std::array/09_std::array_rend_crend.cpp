/// Sequence containers : Array

/// 09_std::array::rend_crend
/// definition in header < array >

/**
reverse_iterator rend();
const reverse_iterator rend() const;
const reverse_iterator crend() const;

Returns a reverse iterator to the element following the last
element of the reversed container. It corresponds to the element
preceding the first element of the non-reversed container. This
element acts as a placeholder, attempting to access it results in
undefined behavior.

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
        std::array<const char*,1>::reverse_iterator it = chs.rend();
        --it;
        std::cout<<"array with 'rbegin ': "<<*it<<std::endl; /// print : farshid



    }

}
