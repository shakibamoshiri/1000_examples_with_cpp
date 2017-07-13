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
/// unique_ptr::get
// Returns a pointer to the managed object or nullptr if no longer is owned.

#include <iostream>
#include <memory>
#include <iomanip>

int main(){
    std::unique_ptr<std::string> uptr_str (new std::string("how are you today?"));

    std::string* str_get = uptr_str.get();

    std::cout << uptr_str.get() << std::endl;   // address
    std::cout << str_get << std::endl;          // the same address as above
    std::cout << *str_get << std::endl;         // how are you today?


    std::unique_ptr<int> uptr_int(new int(100));

    int* pi = uptr_int.get();

    std::cout << uptr_int.get() << std::endl;
    std::cout << pi << std::endl;
    std::cout << *pi << std::endl;
}


