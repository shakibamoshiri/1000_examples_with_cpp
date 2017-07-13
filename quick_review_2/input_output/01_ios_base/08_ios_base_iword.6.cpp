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
    static int count = output.xalloc(); // initialize the count with output.xalloc();
    return output << ++output.iword( count );
}

int main(){
    // internal extensible array

    for( int stuff = 0; stuff < 20; ++stuff )
        std::cout << counter << " : " << stuff << '\n';
}
/**
1 : 0
2 : 1
3 : 2
4 : 3
5 : 4
6 : 5
7 : 6
8 : 7
9 : 8
10 : 9
11 : 10
12 : 11
13 : 12
14 : 13
15 : 14
16 : 15
17 : 16
18 : 17
19 : 18
20 : 19

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.



**/
