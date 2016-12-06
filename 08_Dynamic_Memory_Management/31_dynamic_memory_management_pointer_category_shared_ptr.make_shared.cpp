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
/// std::shared_ptr::shard_make
// Constructs on object of type 'T' and wraps it in a share_ptr using
// 'args' as the parameter list for the constructor of 'T'.
//
// NOTE:
// This function is typically used to replace the construction std::shared_ptr<T> (new T(args..))
// of a shared pointer from the raw pointer returned by a call to new. In contrast to
// that expression, std::make_shared<T> typically allocated memory for the T object and
// for the std::shared_ptr's control block with a single memory allocation
// (this is a non-binding requirement is the standard), where std::shared_ptr<T> (new T(args...))
// preforms at least two memory allocation.
// Moreover, code such as f (std:shared_ptr<int> (new int(32), g())) can caused a
// memory leak if g() throw a exception because g() may be called after new int(32)
// and before the constructor of shared_ptr<int>.
// This does not occur in f(std::make_shared<int>(32),g()), since two function call
// are never interleave

#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


void func (std::shared_ptr<int>& ref){ (*ref)++; }

int main(){
    std::shared_ptr<int> shptr = std::make_shared<int>(22);

    func(shptr); // (*shptr)++

    std::cout << *shptr << '\n';   // 23
}




