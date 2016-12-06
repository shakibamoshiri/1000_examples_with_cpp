/// Sequence containers : Array

/// 03_std::array::operator[] 'braces'
/// definition in header < array >

/**
reference operator[] ( size_type pos );
const_reference operator[] ( size_type pos );
constexpr const_reference operator[] ( size_type pos ) const;

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
