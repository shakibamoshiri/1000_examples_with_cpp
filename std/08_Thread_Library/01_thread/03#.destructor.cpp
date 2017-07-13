/*
        std::thread
        ***********

defined in header <thread>

The class 'thread' represent a single thread of execution.
Threads allows multiple pieces of code to run asynchronously
and simultaneously.

NOTE: std::thread is not CopyConstructible or CopyAssignable.
It is MoveConstructible and MoveAssignable.

    Member type:
        native_handle_type          implementation-defined

    Member classes:
        id                          represents the id of the thread

    Member function:
        constructor                 constructs a new thread
        destructor                  destructs the thread object, underlying thread must be joined or detached
        operator =                  move the thread object

        joinable                    checks whether the thread is joinable, i.e. potentially running in parallel context
        get_id                      returns the id of the thread
        native_handle               returns the underlying implementation-defined thread handle
        hardware_concurrency        returns the number of concurrent threads supported by the implementation

        join                        waits for a thread to finish its execution
        detach                      permits the thread to execute independently from the thread handle
        swap                        swap

    Non-member function:
        std::swap                   specialized the std::swap algorithm

*/

/// std::thread::thread ( destructor )

//  Destroys the thread object
//  If *this has an associated thread ( joinable == true ). std::terminate() ) is called

//  NOTE:
//  A thread object does not have an associated thread ( and is safe to destroy ) after
//  > it was default constructor
//  > it was moved from
//  > join() has been called
//  > detach() has be called


#include <iostream>
#include <thread>


void f(){}

int main(){

    std::thread tr1;    // default constructor is not a thread and joinable() == false

    std::boolalpha( std::cout );
    std::cout << ( tr1.joinable() ) << '\n';    // false

    std::thread tr2( f );   // okay it is a thread

    std::thread tr3 = std::move( tr2 ); // now tr3 is running f() and tr2 is not a thread and joinable() == false
    std::cout << ( tr2.joinable() ) << '\n';    // false

    std::cout << ( tr3.joinable() ) << '\n';    // true

    // and here I do not call join() to see how it acts without joining a thread ( it called std::terminate );
    // tr3.join();
}



/* output:

false
false
true
terminate called without an active exception
Aborted (core dumped)


*/
