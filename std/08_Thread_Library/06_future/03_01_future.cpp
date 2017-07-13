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
/// std::future


#include <iostream>
#include <thread>
#include <future>


int main(){

    // future from a packaged_task
    std::packaged_task< int () > task( [](){ return 7; } ); // wraps the function | int () == int( * )()
    std::future< int > fu1 = task.get_future();             // get a future
    std::thread( std::move( task ) ).detach();              // launch on a thread

    // future from an async()
    std::future< int > fu2 = std::async( std::launch::async, [](){ return 8; } );

    // future from a promise
    std::promise< int > pr;
    std::future< int > fu3 = pr.get_future();
    std::thread( []( std::promise< int > p ){ p.set_value_at_thread_exit( 9 ); }, std::move( pr ) ).detach();

    std::cout << "waiting ..." << std::flush;
    fu1.wait();
    fu2.wait();
    fu3.wait();
    std::cout << "done!\nresult are: "
              << fu1.get() << ' '
              << fu2.get() << ' '
              << fu3.get() << std::endl;

}

/* output for me:


waiting ...done!
result are: 7 8 9
*/








