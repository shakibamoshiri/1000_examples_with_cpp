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
/// std::shared_ptr::~ shared_ptr ( destructor )
// If *this owns an object and it is the last shared_ptr owned it,
// the object is destroyed through the owned deleter.
// After the destruction, the smart pointers that shared ownership
// with *this, if any, will report a use_count() that is one less
// that its previous value.

#include <iostream>
#include <memory>
#include "../helpful/user_assert"

struct stuff {
    stuff (){ std::cout << "stuff...\n"; }
    ~stuff (){ std::cout << "~ stuff...\n"; }
};

int main(){
    std::shared_ptr<stuff> shptr(new stuff);

    std::cout << shptr.use_count() << std::endl;

    user_assert(shptr.get() != nullptr);
    shptr.reset();
    user_assert(shptr.get() == nullptr);

    std::cout << shptr.use_count() << std::endl;
}




