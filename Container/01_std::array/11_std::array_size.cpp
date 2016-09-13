/// Sequence containers : Array

/// 11_std::array::size
/// definition in header < array >

/**
constexpr size_type size();
constexpr size_type size() const ;

Returns the number of element in the container, i.e std::distance ( begin(),end())

Return Value:
True if the container is empty. false otherwise
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
        std::array<const char*, 3> chs {"shakib", "omid", "farshid"};
        std::cout<<chs.size()<<std::endl;
    }

}
