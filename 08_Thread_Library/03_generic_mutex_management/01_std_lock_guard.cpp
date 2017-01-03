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
/// std::lock_guard

//  This class has constructor, destructor, and operator = that is deleted

//  The class std::lock_guard is a mutex wrapper that provides a
//  convenient RAII-style mechanism for owning a mutex or several
//  mutexes (since C++17) for the duration of a scope block
//  for more detail see the main website en.cppreference.com


#include <iostream>
#include <mutex>
#include <thread>


int g_i = 0;
std::mutex g_i_mutex;       // protects g_i

void safe_increment(){

    std::lock_guard< std::mutex > lock ( g_i_mutex );
    ++g_i;

    std::cout << std::this_thread::get_id() << " : " << g_i << '\n';

    // g_i_mutex is automatically released when lock goes out of scope
}

int main(){

    std::cout << __func__ << ": " << g_i << '\n';

    std::thread tr1( safe_increment );
    std::thread tr2( safe_increment );

    tr1.join();
    tr2.join();

    std::cout << __func__ << ": " << g_i << '\n';

}

/* output for me:

main: 0
3073403712 : 1
3065011008 : 2
main: 2

*/
