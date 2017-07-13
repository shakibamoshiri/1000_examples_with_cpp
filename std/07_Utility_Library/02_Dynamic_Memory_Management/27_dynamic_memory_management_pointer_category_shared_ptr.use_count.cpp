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
/// std::shared_ptr::use_count
// Returns the number of different shared_ptr instance (this include)
// manging the current object, if there is no managed object, 0 is returned


#include <iostream>
#include <memory>
// #include "../helpful/user_assert"

struct stuff {
    int num;
        stuff (int t = -1) noexcept : num(t) { }

        ~stuff () {  }

    // overloading for operator * and ->
    const stuff* operator -> () const {
        std::cout << "overload operator -> was called\n";
        return this;
    }
    const stuff& operator * () const {
        std::cout << "overload operator * was called\n";
        return *this;
    }

    //friend std::ostream& operator << (std::ostream& out,const stuff& obj){
    //    return out << obj.num;
    //}
};

void func (std::shared_ptr<stuff> ptr){
    std::cout << "Inside func function: ";
    std::cout << ptr.use_count() << std::endl; // returns 3
}

int main(){
    std::shared_ptr<stuff> shptr;
    std::cout << shptr.use_count() << std::endl; // returns 0

    std::shared_ptr<stuff> shptr1 (new stuff(10));
    std::cout << shptr1.use_count() << std::endl; // returns 1

    std::shared_ptr<stuff> shptr2 (shptr1);
    std::cout << shptr1.use_count() << std::endl; // returns 2

    func(shptr1); // returns 3 inside the function
    std::cout << shptr1.use_count() << std::endl; // returns 2

    /// So it counts managed object in the same scope


}




