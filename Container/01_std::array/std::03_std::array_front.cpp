/// Sequence containers : Array

/// 03_std::array::front
/// definition in header < array >

/**
reference front();
const_reference front() const;
constexpr const_reference front() const;

Returns a reference to the first element in the containers.
calling FRONT on the empty container is undefined.

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
            std::cout<<s<<std::endl;
        std::cout<<"gets front form the a1 array: "<<a1.front()<<std::endl;

        std::cout<<"\n\n";

        std::array<char,10> letters {'a','r','r','a','y','i','n','c','+','+'};
        int i=0;
        for ( const char ch : letters )
            std::cout<<++i<<' '<<ch<<std::endl;

        std::cout<<"\n\ncalling front in letters:\n";
        std::cout<<letters.front()<<std::endl;


    }

}
