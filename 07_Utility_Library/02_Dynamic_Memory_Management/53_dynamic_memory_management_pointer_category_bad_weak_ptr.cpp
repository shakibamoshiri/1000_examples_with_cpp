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
>>>>> bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::bad_weak_ptr
// std::bad_weak_ptr is the type of the object thrown
// as exception by the constructors of std::shared_ptr that
// the std::weak_ptr as the argument, when the std::weak_ptr
// refers to an already deleted object.


#include <iostream>
#include <memory>
//#include "../helpful/user_assert"

int main(){

    std::shared_ptr<int> shp (new int(33));
    std::weak_ptr<int> wp (shp);

    shp.reset();

    try { std::shared_ptr<int> tmp (wp); }
    catch (const std::bad_weak_ptr& err){ std::cout << err.what() << std::endl; }

}




