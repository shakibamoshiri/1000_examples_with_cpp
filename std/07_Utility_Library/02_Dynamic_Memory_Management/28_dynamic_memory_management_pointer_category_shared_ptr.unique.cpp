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
/// std::shared_ptr::unique
// Checks if *this is the only shared_ptr instance managing
// the current object, i.e. whether use_count == 1
//
// returns true for only one managed object, otherwise returns false


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
    std::cout << ptr.unique() << std::endl; //  false
}

int main(){
    std::boolalpha (std::cout);

    std::shared_ptr<stuff> shptr;
    std::cout << shptr.use_count() << std::endl;     // returns 0
    std::cout << shptr.unique() << std::endl;        //  false

    std::shared_ptr<stuff> shptr1 (new stuff(10));
    std::cout << shptr1.use_count() << std::endl;    // returns 1
    std::cout << shptr1.unique() << std::endl;       //  true

    std::shared_ptr<stuff> shptr2 (shptr1);
    std::cout << shptr1.use_count() << std::endl;    // returns 2
    std::cout << shptr2.unique() << std::endl;       //  false

    func(shptr1); // returns 3 inside the function
}




