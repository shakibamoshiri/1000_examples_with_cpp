/// Sequence containers : Array

/// 06_std::array::begin_cbegin
/// definition in header < array >

/**
iterator begin();
const_iterator begin() const;
const_iterator cbegin() const;

Returns an iterator to the first element of the container.
If the container is empty, the returned iterator will be equal to end().

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
        std::cout<<"array with 'begin': "<<*chs.begin()<<std::endl;
        std::cout<<"array with 'cbegin': "<<*chs.cbegin();

    }

}
