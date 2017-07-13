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
/// std::swap (std::unique_ptr)
// Specializes the std::swap algorithm for std::unique_ptr.
// Swaps the pointers of lhs and rhs.
// It calls lhs.swap(rhs)


#include <iostream>
#include <memory>
#include <algorithm>
// #include "../helpful/user_assert"



int main(){
    std::unique_ptr<int> uptr1 (new int (30));
    std::unique_ptr<int> uptr2 (new int (100));

    std::swap(uptr1, uptr2);

    std::cout << *uptr1 << std::endl;   // 100
    std::cout << *uptr2 << std::endl;   // 30

}




