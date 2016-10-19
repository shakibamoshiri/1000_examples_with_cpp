/// Sequence containers : Array

/// 07_std::array::end_cend
/// definition in header < array >

/**
iterator end();
const_iterator end() const;
const_iterator cend() const;

Returns an iterator to the element following the last element
of the container. This element acts as a placeholder; attempting
to access it result in undefined behavior.

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
        std::array<const char*,1>::iterator it = chs.end();
//        std::iterator::reference r = chs.end(); // it is wrong
        --it;
        std::cout<<"array with 'end': "<<*it<<std::endl;


    }

}
