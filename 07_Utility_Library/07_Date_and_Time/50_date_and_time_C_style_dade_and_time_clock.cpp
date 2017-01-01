/*
            Date and Time
            *************

    1. duration
        see the examples from 01 to 28
    -----------------------------------
    2. Clocks:
        see the examples from 29 to 34
    -----------------------------------
    3. Time point
        see the examples from 35 to 47
    -----------------------------------
    C-style data and time library
    Also provided are the C-style data and time functions, such as std::time_t, std::difftime,
    and CLOCKS_PER_SEC.
        Functions
        Defined in header <ctime>

        Time manipulation
        difftime        computes the difference between times
        time            returns the current time of the system as time since epoch
        clock           returns raw processor clock time since the program is started

        Format conversions
        asctime         converts a tm object to a textual representation
        ctime       	converts a time_t object to a textual representation
        strftime        converts a tm object to custom textual representation
        wcsftime        converts a tm object to custom wide string textual representation
        gmtime          converts time since epoch to calendar time expressed as Universal Coordinated Time
        localtime       converts time since epoch to calendar time expressed as local time
        mktime          converts calendar time to time since epoch

        Constants
        CLOCKS_PER_SEC  number of processor clock ticks per second

        Types
        tm              calendar time type
        time_t          time since epoch type
        clock_t         process running time


*/
/// C-style data and time library
//
/// std::clock
//  std::clock_t clock
//
//  Returns the approximate processor time used by the process since
//  the beginning of an implementation-defined are related to the
//  program's execution. To convert result value to seconds divide
//  it by CLOCKS_PER_SEC.



#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>

// #include <unistd.h>

// This example demonstrates the difference between clock() time and real time

void stuff (){
    volatile double tmp(0.0);

    for( int n = 0; n < 10000; ++n)
        for( int m = 0; m < 100000; ++m)
            tmp = n * m;

} // end of the stuff function

int main (){

    std::clock_t cpu_time_start= std::clock();

    std::chrono::time_point< std::chrono::high_resolution_clock > real_time_start = std::chrono::high_resolution_clock::now();

    std::thread tr1 ( stuff );  // first thread
    std::thread tr2 ( stuff );  // second thread
    tr1.join();
    tr2.join();

    std::clock_t cup_time_end = std::clock();

    std::chrono::time_point< std::chrono::high_resolution_clock > real_time_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed
              << std::setprecision( 2 )
              << "CPU time used: "
              << 1000.0 * (cup_time_end - cpu_time_start) / CLOCKS_PER_SEC << " ms"
              << '\n'
              << "wall clock time passed: "
              << std::chrono::duration< double, std::milli>( real_time_end - real_time_start ).count() << " ms"
              << std::endl;

}


/* output for me:

CPU time used: 3132.77 ms
wall clock time passed: 1711.36 ms

*/


