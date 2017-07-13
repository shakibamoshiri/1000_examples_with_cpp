/*
        Dynamic Memory Management
        *************************


C-style Memory Management (defined in header <cstdlib>)
    > std::malloc
    > std::calloc
    > std::realloc
    > std::free

*/
/// std::realloc
// Reallocates the given area of memory.
// It must be previously allocated by std::malloc(), std::calloc() or std::realloc
// and not yet freed with std::free(), otherwise, the results are undefined behavior.


#include <new>
#include <cstdlib>
#include <iostream>
#include "../helpful/user_assert"

class MalloDynamicBuffer {
private:
    char* p;

public:
    explicit MalloDynamicBuffer (std::size_t initial = 0): p(nullptr) { resize(initial);}
    ~MalloDynamicBuffer() { std::free(p); }

    void resize (std::size_t newSize){
        if (newSize == 0) { // this checks is not sticky needed,
            std::free(p);   // but zero-size realloc is deprecated in C
            p = nullptr;
        } else {
            if (void* mem = std::realloc(p, newSize)) p = static_cast<char*>(mem);
            else throw std::bad_alloc();
        }
    }

    char& operator [] (size_t n){ return p[n]; }
    char operator [] (size_t n) const { return p[n]; }
};

int main(){
    MalloDynamicBuffer buf1(1024);
    buf1[5] = 'b';
    buf1.resize(10);    // shrink

    user_assert(buf1[5] == 'b');

    buf1.resize(1024);

    user_assert(buf1[5] == 'b');
}
