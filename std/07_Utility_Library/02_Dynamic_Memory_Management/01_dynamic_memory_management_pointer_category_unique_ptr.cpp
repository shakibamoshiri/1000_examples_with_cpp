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
/// unique_ptr
// std::unique_ptr is a smart pointer that require sole ownership of an
// object through a pointer and destroys that object when the unique_ptr
// goes out of scope. No two unique_ptr instances can manages the same object.
//
// member type:
// :    pointer
// :    element_type
// :    deleter_type
//
// member function:
// :    constructor
// :    destructor
// :    operator =
// :    release
// :    reset
// :    swap
// :    get
// :    get_deleter
// :    operator bool
// :    operator *
// :    operator ->
// :    operator []
//
// non-member function
// :    make_unique
//
// (since c++14)
// :    operator ==
// :    operator !=
// :    operator <
// :    operator >
// :    operator >=
// :    operator <=
// :    std::swap
//
// Fro more detail read the main site.


#include <iostream>
#include <memory>

struct Ball {
    Ball(){ std::cout << "Ball::Ball\n"; }
    ~Ball(){ std::cout << "Ball:: ~ Ball\n"; }
    void getBall(){ std::cout << "Ball::getBall\n"; }
};

void func(const Ball&){ std::cout << "func ( const Ball& )\n"; }

int main(){
    std::unique_ptr<Ball> ptr1(new Ball);   // ptr1 owns Ball

    if( ptr1 ) ptr1->getBall();

    {
        std::unique_ptr<Ball> ptr2( std::move(ptr1));   // now ptr2 owns Ball
        func(*ptr2);

        ptr1 = std::move(ptr2);                         // ownership returns to ptr1
        std::cout << "destroyed ptr2 ... \n";
    }

    if( ptr1 ) ptr1->getBall();
}


