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
/// std::swap (std::weak_ptr)
// Specialized the swap algorithm for std::weak_ptr.
// Swaps the pointers of lhs and rhs.
// Calls lhs.swap(rhs)


#include <iostream>
#include <memory>
#include <algorithm>
//#include "../helpful/user_assert"


void fd (int* ptr){
    std::cout << __func__ << " deleted the pointer...\n";
    delete ptr;
}

int main(){
    std::shared_ptr<int> shptr1 (new int(11),fd);
    std::shared_ptr<int> shptr2 (new int(22),fd);

    std::weak_ptr<int> wptr1 = shptr1;
    std::weak_ptr<int> wptr2 = shptr2;

    std::cout << "before the swap: " << *wptr1.lock() << ' ' << *wptr2.lock() << std::endl;
    // wptr1.swap(wptr2); also okay
    std::swap(wptr1, wptr2);
    std::cout << "after the swap: " << *wptr1.lock() << ' ' << *wptr2.lock() << std::endl;


}




