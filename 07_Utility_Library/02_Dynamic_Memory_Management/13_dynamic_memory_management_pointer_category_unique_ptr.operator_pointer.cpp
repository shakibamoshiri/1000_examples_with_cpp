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
/// unique_ptr::operator *
// operator* or -> provide access to the object owned by *this
// The behavior is undefined if get() == nullptr
//
/// Return value
// 1. Returns the object owned by *this, equivalent to *get()
// 2. Returns a pointer to the object owned by *this, i.e. get().



#include <iostream>
#include <memory>
#include "../helpful/user_assert"

struct S { void func (){ std::cout << "S::func\n"; } };

void f (const S&){ std::cout << "f (cosnt S&)\n"; }

int main(){
    std::unique_ptr<S> uptr (new S);

    user_assert(uptr.get() != nullptr);

    uptr->func();

    f(*uptr);

    (*uptr.get()).func();   // same as uptr->func()

    uptr.get()->func();     // same as uptr->fucn()

    S* ptr;

    ptr->func();            // same as uptr->func() but it is in stack and uptr is on heap
}


