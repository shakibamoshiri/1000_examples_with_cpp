/*
            Program support Utility
            ***********************

Communicating with the Environment:
( in header <stdlib.h> )
( in header <cstdlib> )
    > system            : calls the host environment's command processor
    > getenv            : access the list environment variables

*/
/// std::getenv
//  char* getenv (const char* env_var);
//
//  Searches the environment list provided by the host environment
//  (the OS), for a string that matches the C string  pointed to by
//  'env_var' and returns a pointer to the C string that is associated
//  with the matched environment list member.

#include <iostream>
#include <cstdlib> // std::system
#include <fstream>


int main (){

    const char* evn_ptr = std::getenv("PATH");

    if (evn_ptr) std::cout << "You path is: " << evn_ptr << std::endl;

    // not using *env_pt
    // it gives you the first letter
    // if (evn_ptr) std::cout << "You path is: " << *evn_ptr << std::endl;

}
