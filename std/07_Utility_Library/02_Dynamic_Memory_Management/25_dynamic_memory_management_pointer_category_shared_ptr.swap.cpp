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
/// std::shared_ptr::swap
// Exchanges the contents of *this and the given value


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"

struct stuff {
    int num;
        stuff (int t = 1) noexcept : num(t) {
            std::cout << "constructor ... " << num << '\n'; }

        ~stuff () { std::cout << "destructor ... " << num << '\n'; }
};

int main(){
    std::shared_ptr <stuff> shptr_10 (new stuff(10));   // value is 10
    std::shared_ptr <stuff> shptr_1 (new stuff(1));     // value is 1

    std::cout << shptr_10->num << ' ' << shptr_1->num << '\n';

    std::cout << "after swapping ...\n";
    shptr_10.swap(shptr_1);

    std::cout << shptr_10->num << ' ' << shptr_1->num << '\n';

}




