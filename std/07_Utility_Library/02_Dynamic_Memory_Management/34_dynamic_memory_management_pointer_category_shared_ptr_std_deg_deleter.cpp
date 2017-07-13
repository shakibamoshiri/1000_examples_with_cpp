/*
        Dynamic Memory Management
        *************************

Smart Pointer:
Smart pointers enable automatic, exception-safe, object lifetime management.

Pointer Category (defined in header <memory>)
    > unique_ptr                    smart pointer with unique object ownership semantics
>>>>> shared_ptr                    smart pointer with shared object ownership semantics
    > weak_ptr                      weak reference to an object managed by std::shared_ptr
    > auto_ptr                      smart pointer with strict object ownership semantics
    helper classes
    > owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::get_deleter
// Access to p's (parameter) deleter, if the shared pointer 'p' owned a deleter
// of type cv-unqualified Deleter (e.g if it was created with one of the constructors
// that take a deleter as a parameter), then returns a pointer to the deleter.
// Otherwise returns a null pointer.

#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


struct Bird { int leg; };

void dBird (Bird* ptr){
    std::cout << __func__ << "called\n";
    delete ptr;
}

int main(){
    std::shared_ptr<int> shptr1;

    {
        auto aptr = new Bird;
        std::shared_ptr<Bird> shptr2 (aptr, dBird);
        shptr1 = std::shared_ptr<int>(shptr2, &shptr2->leg);    // aliasing constructor
        // shptr1 is now pointing to an int, but meaning the whole Bird
    }   // shptr2 destroyed (deleter not called)

    // obtain pointer to the deleter
    if (auto dp = std::get_deleter<void(*)(Bird*)>(shptr1)){
        std::cout << "shared_ptr<int> owns a deleter\n";
        if (*dp == dBird) std::cout << "... and it equals &dBird\n";
    else
        std::cout << "The deleter of shard_ptr<int> in null\n";
    }
}




