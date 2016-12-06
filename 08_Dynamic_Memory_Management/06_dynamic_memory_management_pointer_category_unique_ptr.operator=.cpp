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
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// unique_ptr operator =
// It has 2 overload function
// 1. Transfer ownership from r (operator = parameter) to *this as if
// by calling reset( r.release() ) followed by an assignment of get_deleter()
// from std::forward<E>( r.get_deleter() ). ( E means class E )
//
// 2. Effectively the same as calling reset().
//
// NOTE:
// The unique_ptr's assignment operator only accepts r-value, which are typically
// generated by std::move (the unique_ptr class explicitly deletes its l-value
                        // copy constructor and l-value assignment operator.)
//
/// return value: *this


#include <iostream>
#include <memory>
#include <iomanip>

struct B {
    B(){ std::cout << "B constructor\n"; }
    ~B(){ std::cout << "~B destructor\n"; }
};

int main(){

  std::unique_ptr<B> uptr1;

  {
      std::cout << "Creating a new B ... \n";

      std::unique_ptr<B> uptr2 (new B);
      /// uptr1 = uptr2
      /// ERROR
      /// cannot copy unique_ptr
      uptr1 = std::move(uptr2);

      std::cout << "about to leave inner block ...\n";
      // B instance will continue to live
      // despite uptr2 going out of scope

      // utpr1 is owned B
  }   // uptr2 is destroyed

  std::cout << "about to leave program ...\n";


}


