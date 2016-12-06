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
>>>>> enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::enable_shared_from_this
// std::enable_shared_from_this allows an object 't' that is currently managed
// by a std::shared_ptr named 'pt' to safety generate addition std::shared_ptr
// instance pt1, pt2, ... that all shared ownership of 't' with 'pt'.


#include <iostream>
#include <memory>
//#include "../helpful/user_assert"

struct Good : std::enable_shared_from_this<Good> {
    std::shared_ptr<Good> getPtr () { return shared_from_this(); }
};

struct Bad {
    std::shared_ptr<Bad> getPtr () { return std::shared_ptr<Bad>(this); }
    ~Bad (){ std::cout << "destructor ... \n"; }
};

int main(){

  // Good: the two shared_ptrs, share the same object
  std::shared_ptr<Good> g1 (new Good);
  std::shared_ptr<Good> g2 = g1->getPtr();
  std::cout << "g2.use_count() " << g2.use_count() << std::endl;

  // Bad: each shared_ptr thinks it's the only owner of the object
  std::shared_ptr<Bad> b1 (new Bad);
  std::shared_ptr<Bad> b2 = b1->getPtr();
  std::cout << "b2.use_count() " << b2.use_count() << std::endl;

  // UB: double-delete of Bad
}




