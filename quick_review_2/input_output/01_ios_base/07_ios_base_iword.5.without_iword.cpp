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
    static int count = 0;
    return output << ++output.iword( output.xalloc() ); // not a static storage
}

int main(){
    // internal extensible array

    for( int stuff = 0; stuff < 20; ++stuff )
        std::cout << counter << " : " << stuff << '\n';
}
/**

1 : 0
1 : 1
1 : 2
1 : 3
1 : 4
1 : 5
1 : 6
1 : 7
1 : 8
1 : 9
1 : 10
1 : 11
1 : 12
1 : 13
1 : 14
1 : 15
1 : 16
1 : 17
1 : 18
1 : 19

Process returned 0 (0x0)   execution time : 0.003 s
Press ENTER to continue.


**/
