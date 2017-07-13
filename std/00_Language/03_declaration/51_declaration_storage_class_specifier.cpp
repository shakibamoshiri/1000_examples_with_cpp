/**
/// Storage class specifiers
///
The storage class specifiers are a part of the decl-specifier-seq of a
declaration syntax. They control two independent properties of the names
introduced by the declaration: their storage duration, and their linkage.
( linkage, means the act of linking things; a link or system of link. synonym: connection )

auto            automatic storage duration
register        automatic storage duration. Also hints to the complier to place the
                object in the processor's register. ( deprecated )
static          static or thread storage duration and internal linkage
extern          static or thread storage duration and external linkage
thread_local    thread storage duration. since c++11

Only one storage class specifier may appear in the declaration
expect that  thread_local may be combined with static or extern (since c++11)
**/
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage ( const std::string& thread_name){
    ++rage; // modifying outside a lock is okay; this is a thread_local variable
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout<<"Rage counter for "<<thread_name<<": "<<rage<<std::endl;
}


int main(){
    std::thread a(increase_rage, "a"), b(increase_rage, "b");
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout<<"Rage counter for main: "<<rage<<std::endl;
    }
    a.join();
    b.join();
}












