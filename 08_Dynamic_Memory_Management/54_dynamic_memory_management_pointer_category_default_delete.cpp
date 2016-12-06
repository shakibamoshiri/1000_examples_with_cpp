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
>>>>> default_delete                default deleter for unique_ptr

*/
/// std::default_delete
// std::default_delete is the default destructor policy used by
// std::unique_ptr when no deleter is specified.


#include <iostream>
#include <memory>
#include <algorithm>
//#include "../helpful/user_assert"

int main(){
    {
        // std::shared_ptr<int> shptr (new int[10]);
        // the destructor calls delete, undefined behavior
    }

    {
        std::shared_ptr<int> shptr (new int[10], std::default_delete<int[]>());
    }   // the destructor calls delete[], okay

    {
        std::unique_ptr<int> uptr (new int(3));
    }   // unique_ptr int uses default_delete<int>

    {
        std::unique_ptr<int> uptr (new int[10]);
    }   // unique_ptr<int[]> uses default_delete<int[]>

    /// nOTe
    // default_delete can be used anywhere a delete function is needed
    std::vector<int*> vec;

    for (int n = 0; n < 100; ++n) vec.push_back(new int (n)); // filling

    std::for_each(vec.begin(), vec.end(), [](int* t){ std::cout << *t << ' '; }); // printing

    std::for_each(vec.begin(), vec.end(), std::default_delete<int>());  // deleting

}




