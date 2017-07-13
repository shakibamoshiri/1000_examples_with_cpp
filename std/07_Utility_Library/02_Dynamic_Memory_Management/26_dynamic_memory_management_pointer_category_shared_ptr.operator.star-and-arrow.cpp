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
/// std::shared_ptr::swap
// Exchanges the contents of *this and the given value


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"

struct stuff {
    int num;
        stuff (int t = -1) noexcept : num(t) { }

        ~stuff () {  }

    // overloading for operator * and ->
    const stuff* operator -> () const {
        std::cout << "overloaded operator -> was called\n";
        return this;
    }
    const stuff& operator * () const {
        std::cout << "overloaded operator * was called\n";
        return *this;
    }

    //friend std::ostream& operator << (std::ostream& out,const stuff& obj){
    //    return out << obj.num;
    //}
};

int main(){
    stuff one(10);

    std::cout << (*one).num << std::endl;   // calls operator *, output 10
    std::cout << one->num << std::endl;     // calls operator ->, outputs 10

    auto ptr = std::make_shared<stuff> (100);
    std::cout << ptr->num << std::endl;     // calls operator -> in shared_ptr class, outputs 100
    std::cout << (*ptr).num << std::endl;   // calls operator *  in shared_ptr class, outputs 100
    // std::cout << *ptr ; ERROR

}




