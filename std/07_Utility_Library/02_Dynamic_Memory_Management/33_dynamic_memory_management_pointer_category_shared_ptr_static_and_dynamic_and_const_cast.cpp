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
/// std::static_pointer_cast, std::dynamic_pointer_cast, std::const_pointer_cast
// Create a new instance of std::shared_ptr whose managed object type
// is obtained from the r's (parameter) managed object type using a cast
// expression. Both smart pointers will share the ownership of the managed
// object.
// The resulting std::shared_ptr's managed object will be obtained by calling (in inspective order):
//
// static_cast<T*>(r.get())
// dynamic_cast<T*>(r.get())
// const_cast<T*>(r.get())

#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


struct Base {};

struct Derived : Base {
    void func () const { std::cout << "how are you today?\n"; }
};

int main(){
    std::shared_ptr<Base> ptr2Base (std::make_shared<Derived>());

    // ptr2Base->func() is ERROR and will not compile: Base has no member named func

    std::static_pointer_cast<Derived>(ptr2Base)->func();    // okay
    // constructs a temporary shared_ptr then calls operator ->

    static_cast<Derived*>(ptr2Base.get())->func();    // also okay
}




