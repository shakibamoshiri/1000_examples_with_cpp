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
/// std::shared_ptr::shared_ptr ( constructor )
// Constructs new shared_ptr from a variety of pointer types that
// refer to an object manage.
// An optional deleter 'd' can be supplied that is later used to destroy
// the object when no shared_ptr objects own it. By default, a deleter-expression
// for type 'Y' is used as the deleter.
//
// For more detail see the main site.

#include <iostream>
#include <memory>

struct stuff {
    stuff (){ std::cout << "stuff...\n"; }
    ~stuff (){ std::cout << "~ stuff...\n"; }
};

struct deleter {
    void operator() (stuff* ptr){
        std::cout << "call delete for stuff object...\n";
        delete ptr;
    }
};

int main(){
    {
        std::cout << "constructor with no managed object:\n";
        std::shared_ptr<stuff> shptr1;
    }

    {
        std::cout << "constructor with object:\n";

        std::shared_ptr<stuff> shptr2 (new stuff);
        std::shared_ptr<stuff> shptr3 (shptr2);

        std::cout << shptr2.use_count() << std::endl;
        std::cout << shptr3.use_count() << std::endl;
    }

    {
        std::cout << "constructor with object and deleter:\n";

        std::shared_ptr<stuff> shptr4 (new stuff, deleter());
    }
}




