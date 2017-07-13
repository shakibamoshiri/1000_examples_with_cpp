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
/// std::make_unique
// Constructs an object of type T and wraps it in a std::unique_ptr



#include <iostream>
#include <memory>
// #include "../helpful/user_assert"

struct stuff {
    int x, y, z;
    stuff(): x(0), y(0), z(0) {}
    stuff(int t1, int t2, int t3): x(t1), y(t2), z(t3) {}
    friend std::ostream& operator << (std::ostream& out, stuff* temp){
        return out << temp->x << ' ' << temp->y << ' ' << temp->z;
    }
};



int main(){
    // using the default constructor
    std::unique_ptr<stuff> uptr1 = std::make_unique<stuff>();

    // using the constructor that matches three argument
    std::unique_ptr<stuff> uptr2 = std::make_unique<stuff>(2,4,6);

    // creating a unique_ptr to an array of 5 elements
    std::unique_ptr<stuff[]> uptr3 = std::make_unique<stuff[]>(5);

    std::cout << uptr1.get() << std::endl; // return address and it would get by stuff* temp

    std::cout << uptr2.get() << std::endl;  // also

    for (int i = 0; i < 5; ++i){ std::cout << i << ':' << &uptr3[i] << std::endl; }
}




