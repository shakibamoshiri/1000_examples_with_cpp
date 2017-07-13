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
/// std::weak_ptr::lock
// Checks a new std::shared_ptr that shares ownership of the managed
// object, if there is no managed object i.e. *this is empty, then
// the returned shared_ptr is empty
// Effectively returns expired() ? shared_ptr<T>() : shared_ptr<T>(*this), executed automatically.


#include <iostream>
#include <memory>
//#include "../helpful/user_assert"

void observe (std::weak_ptr<int> wptr){
    if (auto observe = wptr.lock()) { std::cout << "\tobserve() able to lock weak_ptr<>, value=" << *observe << '\n'; }
    else { std::cout << "\tobserve() unable to lock weak_ptr<>" << '\n'; }
}

int main(){

    std::weak_ptr<int> wptr;
    std::cout << "weak_ptr<> not yet initialized\n";
    observe(wptr);

    {
        auto shptr = std::make_shared<int> (33);
        wptr = shptr;
        std::cout << "weak_ptr<> initialized with shared_ptr\n";
        observe(wptr);
    }

    std::cout << "shared_ptr<> has been destroyed due to scope exit\n";
    observe(wptr);


}




