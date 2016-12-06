/*
        Dynamic Memory Management
        *************************


C-style Memory Management (defined in header <cstdlib>)
    > std::malloc
    > std::calloc
    > std::realloc
    > std::free

*/
/// std::calloc
// Allocates memory for an array of num objects of size size
// and initializes it to all bits zero.


#include <iostream>
#include <cstdlib>

int main(){
    int* p1 = (int*) std::calloc(4, sizeof (int));     // allocates enough for an array of 4 int
    int* p2 = (int*) std::calloc(1, sizeof(int[4]));       // same, naming the type directly
    int* p3 = (int*) std::calloc(4, sizeof *p3);       // same, without repeating the type name

    if (p1) {
        for (int n = 0; n < 4; ++n) p1[n] = (n * n);    // populates the array

        for (int n = 0; n < 4; ++n) std::cout << "p1[" << n << "] == " << p1[n] << '\n';    // print it back out
    }

    std::free(p1);
    std::free(p2);
    std::free(p3);

}
