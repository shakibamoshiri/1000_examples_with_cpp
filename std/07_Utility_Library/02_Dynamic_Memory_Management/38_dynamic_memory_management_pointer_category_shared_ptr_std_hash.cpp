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
/// std::hash for std::shared_ptr
// The template specialization of std::hash for std::shared_ptr<T>
// allows users to obtain hashes of objects of type std::shared_ptr<T>.
// For a given shared_ptr<T> p, the specialization ensures that std::hash<shared_ptr<T>>()
// (p) == std::hash<T*>()(p.get()).

#include <iostream>
#include <memory>
// #include "../helpful/user_assert"





int main(){
    std::shared_ptr<int> shptr1 (new int(20));
    std::cout << std::hash<int*>()(shptr1.get()) << std::endl;

    std::shared_ptr<int> shptr2 (shptr1);
    std::cout << std::hash<int*>()(shptr2.get()) << std::endl;

    std::shared_ptr<float> shptr3 (new float(3.23));
    std::cout << std::hash<float*>()(shptr3.get()) << std::endl;

}




