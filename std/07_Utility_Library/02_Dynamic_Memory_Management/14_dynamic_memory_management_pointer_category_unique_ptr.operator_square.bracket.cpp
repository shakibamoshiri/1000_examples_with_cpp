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
/// unique_ptr::operator[]
// operator[] provides access to elements of an array managed
// by a unique_ptr.


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


int main(){
    const int size = 10;
    std::unique_ptr<int[]> fact (new int[size]);

    for(int i = 0; i < size; ++i){ fact[i] = (i == 0) ? 1 : i * fact[i - 1]; }

    for(int i = 0; i < size; ++i){ std::cout << i << " : " << fact[i] << '\n'; }
}


