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


int main (int argc, char** argv, char** env){

    while (*env){

//        std::string var = *env;
//        if (var == "USER=shu"){
//            std::cout << *env << std::endl;
//            break;
//        }
       std::cout << *env << std::endl;
        env++;
    }

}
