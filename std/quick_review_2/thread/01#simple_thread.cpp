/*

A review of thread library

*/

#include <iostream>
#include <thread>

void function_1(){
    for( int counter = 0; counter < 10; ++counter ){
        // doing something ...
    }
}

void function_2( const unsigned size ){
    for( unsigned counter = 0; counter < size; ++counter ){
        // doing something ...
    }
}



int main( ){

    std::thread tr1( function_1 );      // spawn new thread that calls function_1
    std::thread tr2( function_2, 20 );  // spawn new thread that calls function_2 and its argument

    std::cout << "main, function_1 and function_2 new execute concurrently...\n";

    // synchronize threads
    tr1.join();         // pause until the function_1 finishes
    tr2.join();         // pause until the function_2 finishes

    std::cout << "function_1 and function_2 completed\n";

}

/* output

main, function_1 and function_2 new execute concurrently...
function_1 and function_2 completed

Process returned 0 (0x0)   execution time : 0.035 s
Press ENTER to continue.




*/
