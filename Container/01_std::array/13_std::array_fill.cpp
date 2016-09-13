/// Sequence containers : Array

/// 13_std::array::fill
/// definition in header < array >

/**
void fill ( const T& value );
Assigns the given value VALUE to all element in the container.

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
        std::array<const char*, 3> chs;
        chs.fill("chs");
        for ( const char* s : chs )
        std::cout<<s<<' ';

        std::cout<<std::endl;

        /// filling with char
        std::array<char,10> ch;
        ch.fill('=');
        for ( char s : ch )
            std::cout<<s<<' ';
    }

}
