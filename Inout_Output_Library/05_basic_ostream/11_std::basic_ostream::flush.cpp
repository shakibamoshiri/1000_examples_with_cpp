/**
std::basic_ostrream
**/


/// 11_std::basic_ostream::flush
/**
basic_ostream& flush();

Writes uncommitted changes to the underlying output sequence.
If rdbuf() is a null pointer, does nothing, otherwise, behave as UnformattedOutputFunction
( since C++11 ). After construction and checking the sentry object, calls rdbuf()->pubsync().
If the call return -1, calls setstate(badbit).
**/


#include <iostream>
#include <thread>
#include <chrono>

void test_flush(){
        std::cout<<"output from thread ... ";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<" ... thread calls flush() \n";
        std::cout.flush();
}
int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        std::thread t1(test_flush);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::clog<<"Output form main \n";
        t1.join();

    }

    {
        /// msdn.microsoft.com
    }

}













