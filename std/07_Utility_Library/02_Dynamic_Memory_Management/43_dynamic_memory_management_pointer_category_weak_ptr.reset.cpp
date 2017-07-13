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
/// std::weak_ptr::reset
// Release the reference of the managed object. After the call *this managed no object.


#include <iostream>
#include <memory>
#include "../helpful/user_assert"


void fd (int* ptr){
    std::cout << __func__ << " deleted the pointer...\n";
    delete ptr;
}

int main(){
    std::shared_ptr<int> shptr (new int(39),fd);

    std::weak_ptr<int> wptr = shptr;

    std::cout << "before calling wptr: expired() = " << wptr.expired() << std::endl;    // 0 (not expired, still exist)
    wptr.reset();
    std::cout << "after calling wptr: expired() = " << wptr.expired() << std::endl;     // 1 ( expired, not exist)
}




