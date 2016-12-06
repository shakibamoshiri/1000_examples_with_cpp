/// Sequence containers : Array

/// 14_std::array::swap
/// definition in header < array >

/**
viod swap ( array& other );

Exchanges the contents of the container with those of "other".
Dose not cause iterator and reference to associate with the
other container.

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

        std::array<const char*,3> lname {"Tahmasibi", "IDont","Bahmani"};
        lname.swap(name);

        for (const char* s : lname )
            std::cout<<s<<std::endl;
        std::array<const char*,1>::iterator it = name.begin();

        while (*it){
            std::cout<<*it<<std::endl;
            it++;
        }
    }

}
