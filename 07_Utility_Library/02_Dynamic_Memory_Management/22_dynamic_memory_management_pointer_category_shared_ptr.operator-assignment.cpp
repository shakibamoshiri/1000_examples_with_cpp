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
/// std::shared_ptr::operator =
// Replace the managed object with the one managed


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"

struct stuff {
    int num;
    stuff (int t): num(t){ std::cout << "stuff...\n"; }
    ~stuff (){ std::cout << "~ stuff..." << num << "\n"; }
};

int main(){
   std::shared_ptr<stuff> shptr(new stuff(10));

   {
       std::shared_ptr<stuff> shptr2(new stuff(100));
       shptr = shptr2;  // unlike unique ptr, with shared_ptr copy assignment is okay

       // now shptr contains 100 not 10
       // and pointer for value 10 is destroyed after exiting from this block
   }

   std::cout << shptr.use_count() << std::endl; // 1
   std::cout << shptr->num << std::endl;        // 100
}




