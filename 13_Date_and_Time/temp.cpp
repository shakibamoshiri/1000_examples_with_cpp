/*
            Date and Time
            *************



*/




#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>


/// Example:

int main (){

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();   // raw time since epoch

    std:time_t now_c = std::chrono::system_clock::to_time_t( now - std::chrono::hours( 24 ) );

    std::cout << "24 hours ago, the time was: "
              << std::put_time( std::localtime( &now_c ), "%F %T" )
              << std::endl;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::cout << "hello world!" << std::endl;
    std::chrono::steady_clock::time_point end   = std::chrono::steady_clock::now();

    std::cout <<  "printing took: "
              << std::chrono::duration_cast< std::chrono::nanoseconds >(end - start).count()
              << " nanoseconds"
              << std::endl;


}


/* output for me:

24 hours ago, the time was: 2016-12-16 15:27:06
hello world!
printing took: 7016 nanoseconds


*/






