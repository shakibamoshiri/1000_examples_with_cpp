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
/// std::shared_ptr::allocate_shared
// Constructs an object of type 'T' and wraps it in a std::shared_ptr
// using 'args' as the parameter list for the constructor of 'T'.
//
// All memory allocation is done using a copy of 'alloc', which satisfies
// the Allocator requirement. The copy constructor and the destructor of
// Alloc must not throw exception.

#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


int main(){
    // no example
}




