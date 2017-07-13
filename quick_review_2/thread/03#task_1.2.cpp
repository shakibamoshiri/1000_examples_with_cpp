/*

A review of thread library

*/

#include <iostream>
#include <chrono>
#include <thread>
#include <utility>

void task_1( unsigned value ){
    while( value-- ){
        std::cout << "task_1: " << value << '\n';
        std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
    }
}
void task_2( unsigned value ){
    while( value-- ){
        std::cout << "task_2: " << value << '\n';
        std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
    }
}
int main( ){

    unsigned value = 10;



    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    std::thread tr1( task_1, std::ref( value ) );
    std::thread tr2( task_2, std::ref( value ) );

    tr1.join();
    tr2.join();

    system_clock::time_point finish = system_clock::now();
    std::cout << "the time to do the task_1 is: "
              << duration_cast< seconds >( finish - start ).count()
              << " seconds\n";



}

/* output
task_1: 9
task_2: 9
task_1: 8
task_2: 8
task_1: 7
task_2: 7
task_1: 6
task_2: 6
task_1: 5
task_2: 5
task_1: 4
task_2: 4
task_1: 3
task_2: 3
task_1: 2
task_2: 2
task_1: 1
task_2: 1
task_1: 0
task_2: 0
the time to do the task_1 is: 0 seconds



*/
