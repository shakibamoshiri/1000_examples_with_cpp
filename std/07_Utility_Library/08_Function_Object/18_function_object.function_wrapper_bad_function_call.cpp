/*
            Function Object
            ***************

1. Polymorphic Function Wrapper
    1.1 function
    ---------------------------
    1.2 mem_fn
    ---------------------------

    1.3 bad_function_call:
        std::bad_function_call is the type of the exception thrown by std::function::operator()
        if the function wrapper has no target.

        member function:
            constructor

        Inherited from std::exception



*/
///  std::bad_function_call

#include <iostream>
#include <functional>



int main (){

    std::function< int () > fobj = nullptr;

    try { fobj(); }
    catch (const std::bad_function_call& er){ std::cerr << er.what() << std::endl; }
}

/* output for me:

bad_function_call

*/


