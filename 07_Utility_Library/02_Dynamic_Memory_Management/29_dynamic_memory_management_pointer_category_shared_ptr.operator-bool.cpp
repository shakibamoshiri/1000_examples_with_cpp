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
/// std::shared_ptr::operator bool
// Checks if *this stores a non-null pointer, i.e, whether get() != nullptr
//
// NOTE:
// an empty shared_ptr (where use_count() == 0) may store a non-null pointer
// accessible by get(), e.g. if it were created using aliasing constructor.


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


typedef std::shared_ptr<const char*> shptrInt_t;

void report (shptrInt_t ptr){
    std::cout << ( ptr ? *ptr : "not a valid pointer" ) << '\n';
}

int main(){

    shptrInt_t ptr;
    report(ptr);

    ptr = shptrInt_t (new const char* ("I think this a valid pointer"));
    report(ptr);

}




