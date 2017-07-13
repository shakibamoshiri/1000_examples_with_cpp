/*
        Dynamic Memory Management
        *************************

Smart Pointer:
Smart pointers enable automatic, exception-safe, object lifetime management.

Pointer Category (defined in header <memory>)
    > unique_ptr                    smart pointer with unique object ownership semantics
    > shared_ptr                    smart pointer with shared object ownership semantics
    > weak_ptr                      weak reference to an object managed by std::shared_ptr
>>>>> auto_ptr                      smart pointer with strict object ownership semantics
    helper classes
    > owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::auto_ptr
// auto_ptr is a smart pointer that manages an object via new expression
// and deletes that object when auto_ptr itself is destroyed. It may be
// used to  provide exception safety for dynamically-allocated objects, for
// passing ownership of dynamically-allocated objects into function and for
// returning dynamically-allocated objects form functions.

/// NOTE:

// auto_ptr is deprecated
// why?
// see here:
// http://stackoverflow.com/questions/3697686/why-is-auto-ptr-being-deprecated

#include <iostream>
#include <memory>
#include <algorithm>
//#include "../helpful/user_assert"


int main(){}




