/*
        Generic Mutex Management
        ************************

Defined in header <mutex>

lock_guard      implements a strictly scope-based mutex ownership wrapper

unique_lock 	implements movable mutex ownership wrapper

shared_lock     implements movable shared mutex ownership wrapper

defer_lock_t
try_to_lock_t
adopt_lock_t	tag type used to specify locking strategy

defer_lock
try_to_lock
adopt_lock      tag constants used to specify locking strategy

*/
/// std::unique_lock

//  This class has constructor, destructor, and operator =
//                 lock, try_lock, try_lock_for, try_lock_until
//                 swap, release, mutex, owns_mutex, operator bool
//                 std::swap

//  The class unique_lock is a general-purpose mutex ownership wrapper
//  allowing deferred locking, time-constrained attempts at locking,
//  recursive locking, transfer of lock ownership, and use with condition variable.

//  This class is movable but copyable


#include <chrono>
#include <mutex>
#include <thread>

struct Box {

    int number_thing;
    std::mutex m;

    //-----------------------//

    explicit Box( int number ) : number_thing( number ) {}

};

void transfer( Box &from, Box &to, int number ){

    // do not actually take the locks yet
    std::unique_lock< std::mutex > lock_1( from.m, std::defer_lock );
    std::unique_lock< std::mutex > lock_2( to.m, std::defer_lock );

    // lock both unique_locks without deadlock
    std::lock( lock_1, lock_2 );

    from.number_thing -= number;
    to.number_thing -= number;

    // 'from.m' and "to.m' mutexes unlocked in 'unique_lock' destructor
}

int main(){

    Box acc1( 100 );
    Box acc2( 50 );

    std::thread tr1( transfer, std::ref( acc1 ), std::ref( acc2 ), 10 );
    std::thread tr2( transfer, std::ref( acc2 ), std::ref( acc1 ), 5 );

    tr1.join();
    tr2.join();

}

/* output for me:


*/
