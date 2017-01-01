/*
        Dynamic Memory Management
        *************************


C-style Memory Management (defined in header <cstdlib>)
    > std::malloc
    > std::calloc
    > std::realloc
    > std::free

*/
/// std::free
// Deallocates the space previously allocated by std::malloc, std::realloc, std::calloc.
// If ptr is a null pointer, the function does nothing.


#include <cstdlib>
#include <iostream>

int main(){
    int* p1 = (int*) std::malloc(10 * sizeof *p1);
    std::free(p1);      // every allocated pointer must be freed

    int* p2 = (int*) std::calloc(10, sizeof *p1);
    int* p3 = (int*) std::realloc(p2, 1000 * sizeof * p3);

    if (p3) {   // p2 not null, means p2 was freed by std::realloc
        std::free(p3);
        std::cout << "p3 was freed\n";
    } else {    // p3 null means, p3 was not freed
        std::free(p2);
        std::cout << "p2 was freed\n";
    }
}
