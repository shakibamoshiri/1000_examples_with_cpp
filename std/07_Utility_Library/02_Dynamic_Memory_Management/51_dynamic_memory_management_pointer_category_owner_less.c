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
>>>>> owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::owner_less
// This function object provides owner-based (as opposed to value-based)
// mixed-type ordering of both weak_ptr and shared_ptr. The order is such
// that two smart pointers compare equivalent only if they are both empty
// or if they both manage the same object, even if the value of the raw
// pointers obtained by get() are different (e.g. because they point at
// different sub-object within the same object)


#include <iostream>
#include <memory>
#include <algorithm>
//#include "../helpful/user_assert"


int main(){
    // no example
}




