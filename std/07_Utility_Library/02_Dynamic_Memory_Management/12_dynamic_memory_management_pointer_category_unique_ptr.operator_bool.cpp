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
/// unique_ptr::operator bool
// Checks weather *this owns an object, i.e. weather get() != nullptr



#include <iostream>
#include <memory>

#define okay std::cout << ""
#define wrong(expr) std::cout << "ERROR in line: " << __LINE__ << " with expression: " << #expr << std::endl
#define user_assert(expr)  ( (expr) ? okay : wrong(#expr) )

int main(){
    std::unique_ptr<float> uptr (new float(12.43));

    user_assert(uptr.get() != nullptr);

    if (uptr) std::cout << "before reset, uptr is:\t" << *uptr << '\n';

    uptr.reset();
    // now uptr = nullptr
    // void reset (std::nullptr_t p = nullptr) // until c++17

    if (uptr) std::cout << "before reset, uptr is:\t" << *uptr << '\n';





}


