/*
        Dynamic Memory Management
        *************************

Smart Pointer:
Smart pointers enable automatic, exception-safe, object lifetime management.

Pointer Category (defined in header <memory>)
    > unique_ptr                    smart pointer with unique object ownership semantics
>>>>> shared_ptr                    smart pointer with shared object ownership semantics
    > weak_ptr                      weak reference to an object managed by std::shared_ptr
    > auto_ptr                      smart pointer with strict object ownership semantics
    helper classes
    > owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::shared_ptr
// std::shared_ptr is a smart pointer that retrains shared ownership
// of an object through a pointer.
// Several shared_ptr object may own the same object. the object is
// destroyed and its memory deallocated when either of the following happens:
// *    the last remaining shared_ptr owning the objects is destroyed
// *    the last remaining shared_ptr owning the objects is assigned
//      another pointer via operator = or reset().
//
// For more detail see the main site
// or see shared_ptr.h
//
/// Member Type:
// element_type
//
/// Member Function:
//  constructor
//  destructor
//  operator =
//  reset
//  swap
//  get
//  operator *
//  operator ->
//  use_count
//  unique
//  operator bool
//  owner_before
//
//  make_shared
//  allocate_shared
//  static_pointer_cast
//  dynamic_pointer_cast
//  const_pointer_cast
//  get_deleter
//  operator ==, !=, <, >, <=, >=
//  operator <<
//  std::swap
//
/// NOTE:
// The ownership of an object can only be shared with another shard_ptr by
// copy constructing or copy assignment its value to another shared_ptr.
// Constructing a new shared_ptr using the raw underlying pointer owned by
// another shared_ptr leads to undefined behavior.

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

// #include "../helpful/user_assert"


struct Base {
    Base (){ std::cout << "Base...\n"; }
    ~Base (){ std::cout << "~ Base...\n"; }
};

struct Derived : public Base {
    Derived (){ std::cout << "Derived...\n"; }
    ~Derived (){ std::cout << "~ Derived...\n"; }
};

void func (std::shared_ptr<Base> ptr){
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // thread-safe, even though the shared use_count is increment
    std::shared_ptr<Base> shptr = ptr;

    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lg(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << "shptr.get() = " << shptr.get()
                  << " , shptr.use_count() = " << shptr.use_count() << std::endl;
    }
}


int main(){
    std::shared_ptr<Base> Bsharedptr = std::make_shared<Derived>();

    std::cout << "create a shared Derived (as a pointer to Base)\n"
              << "Bshardptr.get() = " << Bsharedptr.get()
              << " , Bsharedptr.use_count() = " << Bsharedptr.use_count() << std::endl;

    std::thread tr1 (func, Bsharedptr),
                tr2 (func, Bsharedptr),
                tr3 (func, Bsharedptr);

    Bsharedptr.reset(); // release ownership form main

    std::cout << "shared ownership between 3 threads and released\n"
              << "ownership form main:\n"
              << "Bsharedptr.get() = " << Bsharedptr.get()
              << " , Bsharedptr.use_count() = " << Bsharedptr.use_count() << std::endl;

    tr1.join();
    tr2.join();
    tr3.join();

    std::cout << "All thread completed, the last one deleted Derived\n";
}




