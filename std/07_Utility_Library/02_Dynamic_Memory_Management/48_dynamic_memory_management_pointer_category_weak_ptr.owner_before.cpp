/*
        Dynamic Memory Management
        *************************

Smart Pointer:
Smart pointers enable automatic, exception-safe, object lifetime management.

Pointer Category (defined in header <memory>)
    > unique_ptr                    smart pointer with unique object ownership semantics
    > shared_ptr                    smart pointer with shared object ownership semantics
>>>>> weak_ptr                      weak reference to an object managed by std::shared_ptr
    > auto_ptr                      smart pointer with strict object ownership semantics
    helper classes
    > owner_less                    provide mixed-type owner-based ordering of shared and weak pointers
    > enable_shared_from_this       allows an object to create a shared_ptr referring to itself
    > bad_weak_ptr                  exception thrown when accessing a weak_ptr which refers to already destroyed object
    > default_delete                default deleter for unique_ptr

*/
/// std::weak_ptr::owner_before
// Checks whether this weak_ptr precedes other is implementation
// defined owner-based (as opposed to value-based) order.
//
// returns true if *this precedes other, false otherwise.


#include <iostream>
#include <memory>
//#include "../helpful/user_assert"


struct Bird {
    int n1;
    int n2;
    Bird(int a, int b) : n1(a), n2(b) {}
};

int main()
{
    auto p1 = std::make_shared<Bird>(1, 2);
    std::shared_ptr<int> p2(p1, &p1->n1);
    std::shared_ptr<int> p3(p1, &p1->n2);

    std::cout << std::boolalpha
              << "p2 < p3 " << (p2 < p3) << '\n'
              << "p3 < p2 " << (p3 < p2) << '\n'
              << "p2.owner_before(p3) " << p2.owner_before(p3) << '\n'
              << "p3.owner_before(p2) " << p3.owner_before(p2) << '\n';

    std::weak_ptr<int> w2(p2);
    std::weak_ptr<int> w3(p3);
    std::cout
//              << "w2 < w3 " << (w2 < w3) << '\n'  // won't compile
//              << "w3 < w2 " << (w3 < w2) << '\n'  // won't compile
              << "w2.owner_before(w3) " << w2.owner_before(w3) << '\n'
              << "w3.owner_before(w2) " << w3.owner_before(w2) << '\n';

}




