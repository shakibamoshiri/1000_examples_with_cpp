/*
        Dynamic Memory Management
        *************************

Smart Pointer:
Smart pointers enable automatic, exception-safe, object lifetime management.

Pointer Category (defined in header <memory>)
    > unique_ptr                    smart pointer with unique object ownership semantics
    > shared_ptr                    smart pointer with shared object ownership semantics
    > weak_ptr                      weak reference to an object managed by std::shared_ptr
    > auto_ptr                      smart pointer with strict object ownership semantics
    helper classes
    > owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// unique_ptr::release
// Release the ownership of the managed object if any get()
// returns nullptr after call
//
/// return value:
// pointer to the managed object or nullptr if there was no managed
// object, i.e. the value which would be returned by get() before the call.


#include <iostream>
#include <memory>
#include <iomanip>

struct B {
    B(){ std::cout << "B constructor\n"; }
    ~B(){ std::cout << "~B destructor\n"; }
};

int main(){

    endl( std::cout << "creating a new B ..." );
    std::unique_ptr<B> uptr1 (new B);   // it would be like B* uptr1

    endl( std::cout << "about release B ..." );
    B* p2B = uptr1.release();   // now p2B is ownership


    endl( std::cout << (uptr1.get() == nullptr ? "uptr1.get() == nullptr" : "uptr1.get() != nullptr") );

    endl( std::cout << "B in no longer owned by unique_ptr ..." );

    delete p2B;

}


