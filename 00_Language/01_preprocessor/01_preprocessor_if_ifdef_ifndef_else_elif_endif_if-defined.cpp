///
/// preprocessor
///
/**
The preprocessor supports conditional compilation of parts of source
file. This behavior is controlled by :
#if #else #elif #ifedf # ifndef and #endif directives.

#if and #elif
The expression is a constant expression.

#ifedf and #ifndef
Checks if the identifier was "define" as macro name
#ifdef identifier is essentially equivalent to #if defined ( identifier ).
#ifndef identifier is essentially equivalent to #if !defined ( identifier ).
**/


//#include <unistd.h>
#include <iostream>
#define ABC 2
int main(){
    { /// my sample
    }
    { /// en.reference.com
        #ifdef ABC
            std::cout<<"1 : yes\n";
        #else
            std::cout<<"1 : no\n";
        #endif // ABC

        #ifndef ABC
            std::cout<<"2 : no1\n";
            #elif ABC == 2
            std::cout<<"2 : yes\n";
        #else
            std::cout<<"2 : no\n";
        #endif // ABC

        #if !defined (DDD) && ( ABC < 2*3 )
            std::cout<<"3 : yes\n";
        #endif

        /// After each #if, putting an #endif is necessary.
        #if defined ABC
            std::cout<<"okay , ABC is defined\n";
        #endif // defined

        #if !defined DEF
            std::cout<<"oops!!! DEF is not defined\n";
        #endif


    }
}
