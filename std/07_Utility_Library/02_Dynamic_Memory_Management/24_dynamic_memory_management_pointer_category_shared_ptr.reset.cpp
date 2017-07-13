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
/// std::shared_ptr::reset
// Replaces the managed object with an object pointed to by 'ptr' (parameter in the template function)
// Optional deleter 'd' (parameter in the template function) can be supplied,
// which is later used to destroy the new object when no shared_ptr objects
// own it. By default, delete expression is used as deleter. Proper deleter
// expression corresponding to the supplied type is always selected, this is
// reason why the function is implemented as template using a separate parameter 'Y'.
//
// If *this already owns an object and its is the last shared_ptr owning it,
// the objects is destroyed through the owned deleter
//
// If the object pointed to by ptr is already owned, the function results in undefined behavior.


#include <iostream>
#include <memory>
#include "../helpful/user_assert"

struct stuff {
    private: int num;
    public:
        stuff (int t = -1) noexcept : num(t) {
            std::cout << "constructor ... " << num << '\n'; }

        ~stuff () { std::cout << "destructor ... " << num << '\n'; }

        int getValue () const noexcept { return num; }
};

int main(){
    std::shared_ptr<stuff> shptr = std::make_shared<stuff>(11);
    std::cout << "The first stuff num is:\t" << shptr->getValue() << std::endl;

    // reset the shared_ptr, hand it a fresh instance of stuff
    // the old instance will be destroyed after this call
    shptr.reset(new stuff);
    // constructor is called with default value -1
    // destructor is called and the value 11 is destroyed

    std::cout << "The first stuff num is:\t" << shptr->getValue() << std::endl;
}




