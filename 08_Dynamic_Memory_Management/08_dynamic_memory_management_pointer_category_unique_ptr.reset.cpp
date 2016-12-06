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
/// unique_ptr::reset
// Replaces the managed object.
//
// NOTE:
// To replace the managed object while supplying a new deleter
// as well, move assignment operator may be used. A test for self-reset,
// i.e. weather ptr pointer to an object already managed by *this, is not
// performed, except where provided as a compiler extension or as a debugging
// assert. Note that code such as p.reset(p.release()) does not invoke self-reset,
// only code like p.reset(p.get()) does.


#include <iostream>
#include <memory>
#include <iomanip>

struct B {
    B(){ std::cout << "B constructor\n"; }
    ~B(){ std::cout << "~B destructor\n"; }
};

struct D {
    void operator()( B* ptr){
        endl( std::cout << "calling delete for B object ..." );
        delete ptr;
    }
};

int main(){

    std::cout << "creating a new B object ...\n";
    std::unique_ptr<B, D> uptr (new B(), D());     // uptr owns the B pointer (deleter D)

    endl( std::cout << std::setfill('*') << std::setw(30) << "" );

    std::cout << "replace owned B with a new B ...\n";
    uptr.reset(new B());    // calls deleter for the old one

    endl( std::cout << std::setfill('*') << std::setw(30) << "" );

    std::cout << "replace and delete the owned B ...\n";
    uptr.reset(nullptr);

}


