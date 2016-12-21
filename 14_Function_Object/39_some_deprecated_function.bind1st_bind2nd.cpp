/*
            Function Object
            ***************

5. some deprecated function since c++11
    5.1 base
        unary_function      adaptor-compatible unary function base class
        binary_function     adaptor-compatible binary function base class
    --------------------------------------------
    5.2 binders
        binder1st
        binder2nd           function object holding a binary function and one of its arguments
        bind1st
        bind2nd             binds one argument to a binary function
    --------------------------------------------
    5.3 Function adaptors
        pointer_to_binary_function      adaptor-compatible wrapper for a pointer to binary function
        ptr_fun                         creates an adaptor-compatible function object wrapper from a pointer to function
        mem_fun_t
        mem_fun1_t
        const_mem_fun_t
        const_mem_fun1_t                wrapper for a pointer to nullary or unary member function, callable with a pointer to object
        mem_fun                         creates a wrapper from a pointer to member function, callable with a pointer to object
        mem_fun_ref_t
        mem_fun1_ref_t
        const_mem_fun_ref_t
        const_mem_fun1_ref_t            wrapper for a pointer to nullary or unary member function, callable with a reference to object
        mem_fun_ref                     creates a wrapper from a pointer to member function, callable with a reference to object
*/
// bind1st
// bind2nd             binds one argument to a binary function

#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <algorithm>


int main() {
    std::vector< double > degree = {0, 30, 45, 60, 90, 180};
    std::vector< double > radian( degree.size() );

    double pi = std::acos( -1 );

    std::transform( degree.begin(), degree.end(),
                    radian.begin(),
                    std::bind1st( std::multiplies< double >(), pi / 180.0 ) );
                    // an equivalent lambda: [ pi ]( double a ){ return a * pi / 180.; }
    // and print:
    for( std::size_t index = 0; index < degree.size();
         std::cout << degree[ index ]
                   << "\tdegree == "
                   << radian[ index ]
                   << " radian\n",
                   ++index); // end of for
}







/* output for me:

0       degree == 0 radian
30      degree == 0.523599 radian
45      degree == 0.785398 radian
60      degree == 1.0472 radian
90      degree == 1.5708 radian
180     degree == 3.14159 radian

*/


