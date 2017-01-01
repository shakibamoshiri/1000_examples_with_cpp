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
/// unique_ptr (destructor)
// if get() == nullptr there are no effect. Otherwise, the owned object
// is destroyed via get_deleter()(get()).
// Requires that get_deleter()(get()) goes not throw exception.
//
// NOTE:
// Although std::unique_ptr<T> with the default deleter may be constructed
// with incomplete type T, the type T must be complete at the point of code
// where the destructor is called.


#include <iostream>
#include <memory>
#include <iomanip>

/// Example
// The following program demonstrates usage of a custom deleter

int main(){

    auto deleter = [](int* ptr){ std::cout << "[deleter was called]\n"; delete ptr; };

    std::unique_ptr<int, decltype(deleter)> uptr(new int, deleter);

    std::cout << ( uptr ? "not empty" : "empty" ) << '\n';

    uptr.reset(); // deleting

    std::cout << ( uptr ? "not empty" : "empty" ) << '\n';
}


