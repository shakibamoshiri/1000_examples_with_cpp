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
/// unique_ptr::get_deleter
// Returns the deleter object which would be used for destruction
// of the managed object.


#include <iostream>
#include <memory>

struct Bird {
    Bird(){ std::cout << "Bird ...\n"; }
    ~Bird(){ std::cout << "~Bird ...\n"; }
};

struct D_Bird {
    void func(){ std::cout << "call deleter D_Bird::func() ...\n"; }
    void operator()(Bird* ptr){
        std::cout << "call deleter for Bird object ...\n";
        delete ptr;
    }
};

int main(){
    std::unique_ptr<Bird, D_Bird> uptr (new Bird(), D_Bird());

    D_Bird& del = uptr.get_deleter();

    del.func();
}


