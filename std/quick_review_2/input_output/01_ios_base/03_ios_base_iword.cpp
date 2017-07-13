/*

A review of abstraction section from cplusplus.com

*/
/// ios
//
/// iword
//  long& iword( int index )
//  Get integer element of extensible array

#include <iostream>

// custom manipulator with pre-stream static data
std::ostream& counter ( std::ostream& output ){
    const static int index = output.xalloc();
    return output << ++output.iword( index );
}

int main(){
    // internal extensible array

    std::cout << counter << ": first line\n";
    std::cout << counter << ": second line\n";
    std::cout << counter << ": third line\n";

    // std::cerr has tis owns counter
    std::cerr << counter << ": first error\n";
    std::cerr << counter << ": second error\n";

    // likewise std::logs
    std::clog << counter << ": first log\n";
}
/**
1: first line
2: second line
3: third line
1: first error
2: second error
1: first log

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



**/
