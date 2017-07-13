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
/// std::shared_ptr::owner_before
// Checks whether this shared_ptr precedes 'other' (parameter in function)
// in implementation defined owner-based (opposed to value-based). The order
// is such that two smart pointers compare equivalent only if they are both
// empty of if they both own the same object, even if the value of the pointers
// obtained by get() are different (e.g. because they point at different subobject
// within the same object )
//
// return value:
// true if *this precedes 'other', false otherwise


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"


struct Bird {
    int leg;
    int wing;

    Bird (int l, int w): leg(l), wing(w) {}
};

int main(){
    auto shp1 = std::make_shared<Bird>(1, 2);

    std::shared_ptr<int> shp2 (shp1, &shp1->leg);
    std::shared_ptr<int> shp3 (shp1, &shp1->wing);

    std::boolalpha (std::cout);
    std::cout << "shp2 < shp3 " << (shp2 < shp3) << '\n'
              << "shp3 > shp2 " << (shp2 > shp3) << '\n' // (shp2 > shp3) equivalent (shp3 < shp2)
              << "shp3.owner_before(shp3) " << shp3.owner_before(shp3) << '\n'
              << "shp2.owner_before(shp2) " << shp2.owner_before(shp2) << '\n';

    std::weak_ptr<int> wp2 (shp2);
    std::weak_ptr<int> wp3 (shp3);

    std::cout << '\0'
//              << "wp2 < wp3 " << (wp2 < wp3) << '\n'
//              << "wp3 > wp2 " << (wp3 > wp2) << '\n'
              << "wp2.owner_before(wp3) " << wp2.owner_before(wp3) << '\n'
              << "wp3.owner_before(wp2) " << wp3.owner_before(wp2) << std::endl;
}




