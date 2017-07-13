/// Sequence containers : Array

/// 00_std::array
/// definition in header < array >

/**


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
        std::array<int, 3> a1 { {1,2,3} }; /// double-braces required in c++11 and not c++14
        std::array<int, 3> a2 = {11,12,13}; /// never require after  =
        std::array<std::string, 3> s3 = {std::string("string c++ style"),"string c style"};

        /// container operator are supported
        std::sort(a1.begin(),a1.end());
        std::reverse_copy(a2.begin(),a2.end(),std::ostream_iterator<int>(std::cout," "));

        std::cout<<std::endl;

        /// range for loop is supported
        for ( const std::string s : s3) /// or we can use ( cosnt auto s : s3 )
            std::cout<<s<<std::endl;
    }

}
