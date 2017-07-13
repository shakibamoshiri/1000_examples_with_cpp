/*

A review of thread library

*/

#include <iostream>
#include <chrono>

void task_1( unsigned value ){
    while( value-- ){
        // doing something ...
    }
}

int main( ){

    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();
    task_1( 4'000'000'000 );
    system_clock::time_point finish = system_clock::now();
    std::cout << "the time to do the task_1 is: "
              << duration_cast< seconds >( finish - start ).count()
              << " seconds\n";



}

/* output

the time to do the task_1 is: 10 seconds

Process returned 0 (0x0)   execution time : 10.453 s
Press ENTER to continue.


*/
