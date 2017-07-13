/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>



/// shuffle
//  Randomly rearrange elements in range using generator.




int main(){

    int array[] = { 1,2,3,4,5,6,7,8,9 };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle( std::begin( array ), std::end( array ),
                  std::default_random_engine( seed ) );
    for( const int i : array ){
        std::cout << i << ' ';
    }
}

/* output

1 6 8 9 7 2 3 5 4
Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



*/
