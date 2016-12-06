/*
        Dynamic Memory Management
        *************************


Low Level Memory Management (defined is header <new>)

    The new-expression is the only way to create an object or an array of object
    with dynamic storage duration, that is, with lifetime not restricted to the
    scope in which it is created.
    A new-expression obtains storage by calling an allocation function. A delete-expression
    destroys a most derived object or an array created by a new-expression and calls
    the deallocation function. The default allocation and deallocation functions, along
    with related functions types, and objects, are declared in the header <new>.

    > operator new
    > operator delete
    > std::get_new_handler
    > std::set_new_handler
    > std::bad_alloc
    > std::bad_array_new_length
    > std::nothrow_t
    > std::new_handler
    > std::nothrow
*/
/// std::bad_array_new_length
//  std::bad_array_new_length is the type of the object thrown exceptions
//  by the new-expression to report invalid array length if:
//  1)  array lengths is negative
//  2)  total size of the new array would exceed implementation-defined maximum value
//  3)  the number of initializer-clauses exceeds the number of elements to initialize
//      only the first array dimension may generate this expression; dimensions other
//      than the first are constant expression and are checked at compile time.

#include <iostream>
#include <new>
#include <climits>



int main(){
    int negative = -1;
    int small = 1;
    int large = INT_MAX;

    try {
        new int[negative];      // negative size
    } catch (const std::bad_array_new_length& er){ std::cout << er.what() << std::endl; }

    try {
        new int[small]{1,2,3};  // too many initializer
    } catch (const std::bad_array_new_length& er){ std::cout << er.what() << std::endl; }

    try {
        new int[large][10000];  // too large
    } catch (const std::bad_array_new_length& er){ std::cout << er.what() << std::endl; }


}
