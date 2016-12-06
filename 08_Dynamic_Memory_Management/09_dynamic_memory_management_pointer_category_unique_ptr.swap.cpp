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
/// unique_ptr::swap
// Swaps the managed object and associated deleters of *this
// and another unique_ptr object other.

#include <iostream>
#include <memory>
#include <iomanip>

struct B {
    int size;

    B(int i): size(i){ std::cout << "B constructor\n"; }
    ~B(){ std::cout << "~B destructor\n"; }
};

int main(){
    std::unique_ptr<B> uptr1 (new B(1));
    std::unique_ptr<B> uptr2 (new B(2));

    std::cout << "before swapping:\n";
    std::cout << "uptr1->size:\t" << uptr1->size << '\n';
    std::cout << "uptr2->size:\t" << uptr2->size << '\n';

    uptr1.swap(uptr2);

    std::cout << "after swapping:\n";
    std::cout << "uptr1->size:\t" << uptr1->size << '\n';
    std::cout << "uptr2->size:\t" << uptr2->size << '\n';


}


