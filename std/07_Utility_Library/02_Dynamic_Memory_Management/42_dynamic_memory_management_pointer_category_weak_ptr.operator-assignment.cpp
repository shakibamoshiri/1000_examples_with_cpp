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
/// std::weak_ptr::operator =
// Replace the managed object with the one managed by 'r' (parameter)
// The object is shared with 'r'. if 'r' managed no object, *this manages
// no object too.


#include <iostream>
#include <memory>
#include "../helpful/user_assert"


void fd (int* ptr){
    std::cout << __func__ << " deleted the pointer...\n";
    delete ptr;
}

int main(){
    std::shared_ptr<int> shptr (new int(39),fd);

    std::weak_ptr<int> wptr1 = shptr;
    std::cout << "wptr1 : " << *wptr1.lock() << std::endl;

    std::weak_ptr<int> wptr2 = wptr1;
    std::cout << "wptr2 : " << *wptr2.lock() << std::endl;

    std::weak_ptr<int> wptr4;

    std::cout << "before move wptr1.expire() : " << wptr1.expired() << std::endl;       // 0 it means not expired
    wptr4 = std::move(wptr1);
    std::cout << "agter move wptr4.lock() : " << *wptr4.lock() << std::endl;            // 38
    std::cout << "after move wptr1.expire() : " << wptr1.expired() << std::endl;        // 1 it means expired
}




