/*

    thread support library
    **********************
Defined in header <future>

    std::future
    ***********

The class template std::future provides a mechanism to access the
result of asynchronous operations.
NOTE:
the std::future references shared state that is not shared with any
other asynchronous return objects ( as opposite to std::shared_future )

    Member function:
        constructor
        destructor
        operator =
        share

        get

        valid
        wait
        wait_for
        wait_until

*/
/// std::future::wait

//  Blocks until the result becomes available.
//  valid() == true after the call.
//  The behavior in undefined if valid() == false before the call to this function.


#include <iostream>
#include <thread>
#include <future>

int fibonacci( int number ){
    if( number < 3 ) return 3;
    else return fibonacci( number - 1) + fibonacci( number - 2 );
}

int main(){

    std::future< int > future_1(
        std::async(
            std::launch::async,
            []{ return fibonacci( 20 ); }
        )
    );

    std::future< int > future_2(
        std::async(
            std::launch::async,
            []{ return fibonacci( 23 ); }
        )
    );

    std::cout << "waiting...\n";
    future_1.wait();
    future_2.wait();

    std::cout << "future_1: " << future_1.get() << '\n';
    std::cout << "future_2: " << future_2.get() << '\n';
}

/* output for me:

waiting...
future_1: 20295
future_2: 85971

*/








