/// Sequence containers : Array

/// 17_std::swap ( std::array, std::array)
/// definition in header < array >

/**

template<Class T, std::size_t N>
    void swap ( array<T, N>& rhs, array<T, N>& lhs);

Specializes the std::swap algorithm for std::array. Swaps the
contents of lhs and rhs. Call lhs.swap(rhs).

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

        std::array<const char*,3> lname {"A", "B","C"};
        std::cout<<"Before swapping the first element is: "<<*name.begin()<<std::endl<<"And after that the first element is: ";
        std::swap(name, lname);
        std::array<const char*,1>::iterator it = name.begin();
        std::cout<<*it;

    }

}
