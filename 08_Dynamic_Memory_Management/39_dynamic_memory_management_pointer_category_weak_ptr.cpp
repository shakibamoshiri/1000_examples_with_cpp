/*
        Dynamic Memory Management
        *************************

Smart Pointer:
Smart pointers enable automatic, exception-safe, object lifetime management.

Pointer Category (defined in header <memory>)
    > unique_ptr                    smart pointer with unique object ownership semantics
    > shared_ptr                    smart pointer with shared object ownership semantics
>>>>> weak_ptr                      weak reference to an object managed by std::shared_ptr
    > auto_ptr                      smart pointer with strict object ownership semantics
    helper classes
    > owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::weak_ptr
// std::weak_ptr is a smart pointer that holds a non-owning ("weak") reference
// to an object that is managed by std::shared_ptr. It must be converted to
// std::shared_ptr in order to access the reference object.
//
// std::weak_ptr models temporary ownership: when an object needs to be accessed
// only if exist. and it may be deleted at any time by someone else, std::weak_ptr
// is used to track the object, and it is converted to std::shared_ptr to assume
// temporary ownership.
// If the original std::shared_ptr is destroyed at this time, the objects's lifetime
// is extended until the temporary std::shared_ptr is destroyed as well.
// In addition, std::weak_ptr is used to break circular reference of std::shared_ptr.


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"

std::weak_ptr<int> gw;

void func (){
    if (auto aptr = gw.lock()){ std::cout << *aptr << std::endl; }
    else { std::cout << "gw is expired\n"; }
}

int main(){
    {
        auto aptr = std::make_shared<int> (32);
        gw = aptr;

        func(); // after this calling 'gw' is expired
    }

    func();
}




