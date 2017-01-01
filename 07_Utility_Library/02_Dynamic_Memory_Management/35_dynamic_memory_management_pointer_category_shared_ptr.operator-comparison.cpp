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
/// std::get_deleter::operator == < > <= >= !=
// Compares two shared_ptr<T> objects or compare shared_ptr<T> with a null pointer
//
/// NOTE:
// The comparison operators for shared_ptr simply compare pointer value;
// the actual objects pointed to, are not compared. Having operator <
// defined for shared_ptr allows shared_ptrs to be used as keys in associative
// containers, like std::map and std::set.

#include <iostream>
#include <memory>
// #include "../helpful/user_assert"



int main(){
    std::shared_ptr<int> shptr1;
    std::cout << ( shptr1 == nullptr ? "shptr1 == nullptr" : "shptr1 != nullptr" ) << std::endl;

    std::shared_ptr<int> shptr2(new int(3));
    std::cout << ( shptr2 == nullptr ? "shptr2 == nullptr" : "shptr2 != nullptr" ) << std::endl;

    std::shared_ptr<int> shptr3 (shptr2);
    std::cout << ( shptr3 == shptr2 ? "shptr3 == shptr2" : "shptr3 != shptr2" ) << std::endl;

    std::cout << ( shptr3 == shptr1 ? "shptr3 == shptr1" : "shptr3 != shptr1" ) << std::endl;

}




