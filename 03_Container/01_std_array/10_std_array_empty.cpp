/// Sequence containers : Array

/// 10_std::array::empty
/// definition in header < array >

/**
constexpr bool empty();
constexpr bool empty() const;

Checks if the containers has no element, i.e whether begin() == end().

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
        std::array<const char*, 3> chs = {"shakib", "omid", "farshid"};
        std::cout<<std::boolalpha<<chs.empty()<<std::endl;
        std::array<char,0> number;
        std::cout<<std::boolalpha<<number.empty()<<std::endl;



    }

}
