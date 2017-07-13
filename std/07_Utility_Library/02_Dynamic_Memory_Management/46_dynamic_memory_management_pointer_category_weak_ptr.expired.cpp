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
/// std::weak_ptr::expired
// Checks whether the managed object has already been deleted.
// Equivalent to use_count() == 0
//
// return value is true or false


#include <iostream>
#include <memory>
#include "../helpful/user_assert"


void fd (int* ptr){
    std::cout << __func__ << " deleted the pointer...\n";
    delete ptr;
}

int main(){

    std::shared_ptr<int> shptr1 (new int(11),fd);

    std::weak_ptr<int> wptr1 (shptr1);

    std::cout << ( !wptr1.expired() ? "okay | has managed object" : "sorry | has no managed object" ) << '\n'; // return false so I use !
    wptr1.reset();
    std::cout << ( !wptr1.expired() ? "okay | has managed object" : "sorry | has no managed object" ) << '\n'; // return true  so I use !



}




