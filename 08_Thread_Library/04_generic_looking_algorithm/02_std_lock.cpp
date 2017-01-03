/*
        Generic Mutex Algorithm
        ***********************

try_lock        attempts to obtain ownership of mutexes via repeated calls to try_lock
lock            locks specified mutexes, blocks if any are unavailable

Call once:

once_flag       helper object to ensure that call_once invokes the function only once
call_once       invokes a function only once even if called from multiple threads
*/

/// std::try_lock

//  Tries to lock each of the given Lockable objects lock1, lock2, ..., lockN
//  by calling try_lock in order beginning with the first.

//  return value:
//  1 on success, or 0-based index value of the object that failed to lock

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include <functional>

struct Employee {

    std::vector< std::string > lunch_partners;
    std::string id;
    std::mutex mutex;

    Employee( std::string temp ) : id( temp ) {}

    std::string output() const {
        std::string ret = "Employee " + id + " has lunch partners: ";

        for( const std::string& partner : lunch_partners ){
            ret += partner + " ";

            return ret;
        }
    }

};

void send_mail( Employee&, Employee& ){ // has not parameter just for simulating
    // simulate a time-consuming messaging operation
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

}

void assign_lunch_partner( Employee& emp_1, Employee& emp_2 ){

    {
        static std::mutex io_mutex;
        std::lock_guard< std::mutex > lk( io_mutex );
        std::cout << emp_1.id << " and " << emp_2.id << " are waiting for locks\n";

    }

    // use std::lock to acquire two locks  without worrying about
    // other calls to assign_lunch_partner deadlocking us
    {
        std::lock( emp_1.mutex, emp_2.mutex );
        std::lock_guard< std::mutex > lk_1( emp_1.mutex, std::adopt_lock );
        std::lock_guard< std::mutex > lk_2( emp_2.mutex, std::adopt_lock );
        // Equivalent code: (if unique_lock's is needed, e.g. for condition variables)
//        std::unique_lock< std::mutex > lk_1( emp_1.mutex, std::defer_lock );
//        std::unique_lock< std::mutex > lk_2( emp_2.mutex, std::defer_lock );
//        std::lock( lk_1, lk_2 );
        std::cout << emp_1.id << " and " << emp_2.id << " got locks " << std::endl;
        emp_1.lunch_partners.push_back( emp_1.id );
        emp_2.lunch_partners.push_back( emp_2.id );
    }

    send_mail( emp_2, emp_2 );
    send_mail( emp_1, emp_2 );

}



int main(){

    Employee alice( "Alice" ),
             bob( "Bob" ),
             christian( "Christina" ),
             dave( "Dave" );

    // assign in parallel threads because mailing users about lunch
    // assignment takes a long time
    std::vector< std::thread > vector_of_thread;
    vector_of_thread.emplace_back( assign_lunch_partner,
                                   std::ref( alice ),
                                   std::ref( bob ) );
    vector_of_thread.emplace_back( assign_lunch_partner,
                                   std::ref( christian ),
                                   std::ref( bob ) );
    vector_of_thread.emplace_back( assign_lunch_partner,
                                   std::ref( christian ),
                                   std::ref( alice ) );
    vector_of_thread.emplace_back( assign_lunch_partner,
                                   std::ref( dave ),
                                   std::ref( bob ) );

    for( std::thread& tr : vector_of_thread ) tr.join();
    std::cout << alice.output() << '\n'
              << bob.output() << '\n'
              << christian.output() << '\n'
              << dave.output() << std::endl;




}

/*

Alice and Bob are waiting for locks
Christina and Alice are waiting for locks
Christina and Alice got locks
Christina and Bob are waiting for locks
Christina and Bob got locks
Alice and Bob got locks
Dave and Bob are waiting for locks
Dave and Bob got locks
Employee Alice has lunch partners: Alice
Employee Bob has lunch partners: Bob
Employee Christina has lunch partners: Christina
Employee Dave has lunch partners: Dave
*/
