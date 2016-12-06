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
/// std::weak_ptr::use_count
// Returns the numbers of shared_ptr instances that shared ownership
// of the managed object, or 0 if the managed object has already been deleted
// i.e. *this is empty


#include <iostream>
#include <memory>
#include "../helpful/user_assert"


void fd (int* ptr){
    std::cout << __func__ << " deleted the pointer...\n";
    delete ptr;
}

int main(){


    std::weak_ptr<int> wptr1;

    {
        std::shared_ptr<int> shptr1 (new int(11),fd);
        wptr1 = shptr1;
        std::cout << "inside the scope: wtpr.use_count(): " << wptr1.use_count() << std::endl;
    }

    std::cout << "outside the scope: wtpr.use_count(): " << wptr1.use_count() << std::endl;

}




