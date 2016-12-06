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
/// std::hash
// The template specialization of std::hash for std::unique_ptr<T, Deleter>
// allows users to obtain hashes of objects of type std::unique_ptr<T, Deleter>.


#include <iostream>
#include <memory>
#include <algorithm>
// #include "../helpful/user_assert"

struct stuff {
    stuff (){ endl( std::cout << "stuff ... "); }
   ~stuff (){ endl( std::cout << "~stuff ... "); }
};

int main(){
    stuff* ptr = new stuff();
    std::unique_ptr<stuff> uptr (ptr);

    std::cout << "hash ptr:\t" << std::hash<stuff*>()(ptr) << '\n';
    std::cout << "hash uptr:\t" << std:: hash<std::unique_ptr<stuff>>()(uptr) << '\n';

}




