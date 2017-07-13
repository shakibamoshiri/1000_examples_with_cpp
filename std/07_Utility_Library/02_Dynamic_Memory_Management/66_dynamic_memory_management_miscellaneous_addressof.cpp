/*
        Dynamic Memory Management
        *************************


Miscellaneous (in header <memory>)
    > pointer_traits                provides information about pointer-like types
    > addressof                     obtains actual address of an object, even if that & operator is overloaded
    > align                         aligns a pointer in a buffer

*/
/// std::addressof
// Obtains the actual address of the object of function 'arg',
// even in presence of overloading operator &

#include <iostream>
#include <memory>

template<class T>
struct Ptr {
    T* pad;     // add pad to show difference between 'this' and 'data'
    T* data;

    Ptr (T* arg): pad(nullptr), data(arg) { std::cout << "constructor this:\t" << this << std::endl; }
    ~Ptr () { delete data; }

    T** operator & () { return &data; }
};

template<class T> void func (Ptr<T>* p){ std::cout << "Ptr overload called with p:\t" << p << std::endl; }

void func (int** p){ std::cout << "int** overload called p:\t" << p << std::endl; }

int main(){
    Ptr<int> p (new int(33));

    func(&p);       // calls int** overload

    func(std::addressof(p));    // calls Ptr<int*> overload, (=this)

    // std::addressof(p)->data;
    // std::addressof(p)->pad;
}




