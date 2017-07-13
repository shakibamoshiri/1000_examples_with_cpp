/*
Initialization:
    value       initialization
    copy        initialization
    direct      initialization
    aggregate   initialization
    list        initialization
    reference   initialization
    zero        initialization
    constant    initialization
********************************
Zero Initialization
Sets the initial value of an object to zero.
Syntax:

1   static T object;
2   int();
3   char array[n] = "";

*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>

double d[3];        // zero-initialization to three 0.0's
int* p;             // zero-initialization to null pointer value
std::string s;      // zero-initialization to indeterminate value
                    // then default-initialized to ""

int main(int argc, char** argv){
    static int n = argc;    // zero-initialization to 0
                            // then copy-initialization to argc
    delete p;               // safe to delete p null pointer
}










