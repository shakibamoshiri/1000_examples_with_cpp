/*
        Dynamic Memory Management
        *************************


Miscellaneous (in header <memory>)
    > pointer_traits                provides information about pointer-like types
    > addressof                     obtains actual address of an object, even if that & operator is overloaded
    > align                         aligns a pointer in a buffer

*/
/// std::align
// Given a pointer ptr to a buffer of size space, returns a pointer
// aligned by the specified alignment for size number of types and
// decreases space argument by the number of bytes used for alignment.
// The first aligned address is returned.
// The function modifies the pointer only if it would be possible to fit
// the wanted number of bytes aligned by the given alignment into the buffer.
// If the buffer is too small, the function does nothing and returns nullptr.
// The behavior is undefined if 'alignment' is not a fundamental or extended
// alignment value supported by the implementation (until c++17) power of two (since c++17)

#include <iostream>
#include <memory>

template<std::size_t N>
struct MyAllocator {

    char data[N];
    void* p;
    std::size_t sz;
    MyAllocator () :p(data), sz(N) {}

    template<typename T>
    T* aligned_alloc (std::size_t t = alignof(T)){
        if (std::align(t, sizeof(T), p, sz)){
            T* result = reinterpret_cast<T*>(p);
            p = (char*)p + sizeof(T);
            sz -= sizeof(T);
            return result;
        }
        return nullptr;
    }
};

int main(){
    MyAllocator<64> one;

    // allocator a char
    char* p1 = one.aligned_alloc<char>();
    if (p1) *p1 = 'A';
    std::cout << "allocator a char at: " << (void*)p1 << '\n';

    std::cout << (std::string(30, '*')) << std::endl;

    // allocator an int
    int* p2 = one.aligned_alloc<int>();
    if (p2) *p2 = 20;
    std::cout << "allocator an int at: " << (void*)p2 << '\n';

    std::cout << (std::string(30, '*')) << std::endl;

    // allocator an int, aligned at 32 byte boundary
    int* p3 = one.aligned_alloc<int>(32);
    if (p3) *p3 = 333;
    std::cout << "allocator an int at: " << (void*)p3 << "(32 byte alignment)\n";
}
