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
/// unique_ptr (constructor)
// For more detail if you want, see the main site


#include <iostream>
#include <memory>
#include <iomanip>


struct G {  // object to manage
    G(){ std::cout << "G constructor\n"; }
    G(const G&){ std::cout << "G copy constructor\n"; }
    G(G&&){ std::cout << "G move constructor\n"; }
    ~G(){ std::cout << "~G destructor\n"; }
};
struct D { // deleter
    D(){}
    D(const D&){ std::cout << "D copy constructor\n"; }
    D(D&){ std::cout << "D non-const copy constructor\n"; }
    D(D&&){ std::cout << "D move constructor\n"; }

    void operator()(G* gptr) const {
        std::cout << "D is deleting a G\n";
        delete gptr;
    }
};

int main(){
    // There is 7 overload of constructor for unique_ptr
    // you can see unique_ptr.h

    // example for 3
    D d;
    {   // deleter type is not a reference
        std::unique_ptr<G, D> ptr3(new G, d);   // deleter copied
    }
    {   // deleter type is a reference
        std::unique_ptr<G, D&> ptr3b(new G, d); // ptr3b holds a reference to d
    }
    endl( std::cout << std::setfill('*') << std::setw(20) << "" );

    // example for 4
    {
        std::unique_ptr<G, D> ptr4(new G, D()); // deleter moved
    }
}


