/*
            Function Object
            ***************

3. Reference Wrapper
    3.1 reference_wrapper
        std::reference_wrapper is a class template that wraps a reference
        in a copyable, assignable object. It is frequently used as a mechanism
        to store reference inside standard containers (like: std::vector) which
        cannot normally hold reference.

    --------------------------------------------
    3.2 ref and cref
        Function template ref and cref are helper function that generate
        an object of type std::reference_wrapper, using template argument
        deduction to determine the template argument of type result.

*/
///  std::ref and std::cref

#include <iostream>
#include <functional>

void f (int& n1, int& n2, const int& n3){
    std::cout << n1 << ' '
              << n2 << ' '
              << n3 << std::endl;

    ++n1;   // increments the copy of n1 stored in the function object
    ++n2;   // increments the main's n2
    // ++n3 // compiler error
}

int main() {

    int n1 = 1,
        n2 = 2,
        n3 = 3;

    std::function< void () > bound2f = std::bind( f,                // function itself
                                                 n1,                // n1, pass by value
                                                 std::ref( n2 ),    // n2, pass by reference
                                                 std::cref( n3 ) ); // n3, is const, so pass by reference but const

    n1 = 10, n2 = 11, n3 = 12;

    std::cout << "the values before calling bound2f: "
              << n1 << ' '
              << n2 << ' '
              << n3 << '\n';

    std::cout << "bound2f was called ";
    bound2f();  // passing the parameter are stored in-place in bound2f, so no need the use argument

    std::cout << "the values after calling bound2f: "
              << n1 << ' '
              << n2 << ' '
              << n3 << std::endl;


}


/* output for me:

the values before calling bound2f: 10 11 12
bound2f was called 1 11 12
the values after calling bound2f: 10 12 12

*/


