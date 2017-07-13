/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression
    11 dependent names
    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>

template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };


/// 05 template argument deduction
/**

Deallocation Function Template
Template argument deduction is used when determining if deallocation function
template specialization matches a given placement form of 'operator new'

**/

struct X {
    X() { throw std::runtime_error(""); }
    static void* operator new ( std::size_t sz, bool b ) { return ::operator new ( sz ); }
    static void* operator new ( std::size_t sz, double f ) { return ::operator new ( sz ); }
    template<typename T> static void operator delete ( void* ptr, T arg ) {
        ::operator delete ( ptr );
    }
};

int main(){

    try {
        X* p1 = new ( true ) X; // when X() throws, operator delete id looked up
                                // P1 = void ( void*, T ) A1 = void ( void*, bool ): deduced T = bool
                                // P2 = void ( void*, T ) A2 = void ( void*, double ): T = double
                                // overload resolution picks operator delete<bool>
    } catch ( const std::exception& ) {}
    try {
        X* p1 = new (22.3) X;   // same lookup, picks operator delete<double>
    } catch ( const std::exception& ) {}

return 0; }

