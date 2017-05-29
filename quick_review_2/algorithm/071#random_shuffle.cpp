/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <ctime>



/// random_shuffle
//  Randomly rearrange elements in range




int main(){

    int array[] = { 1,2,3,4,5,6,7,8,9 };
    std::random_shuffle( std::begin( array ), std::end( array ) );
    for( const int i : array ){
        std::cout << i << ' ';
    }

    puts( "\n-----------" );
    std::random_shuffle( std::begin( array ), std::end( array ), [](const int i){ return std::rand() % i + 1; } );
    for( const int i : array ){
        std::cout << i << ' ';
    }
}

/* output

5 4 8 9 1 6 3 2 7
-----------
5 8 4 6 2 7 1 9 3
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
