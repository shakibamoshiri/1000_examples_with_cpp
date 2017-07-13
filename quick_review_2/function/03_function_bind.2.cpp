/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::bind
//  template< class Fn, class... Args >
//  ???  bind( Fu&& function, Args&&... args ){}
//
//  template< class Ret, class Fn, class... Args >
//  ???  bind( Fu&& function, Args&&... args ){}
//
//  binds function arguments.


#include <iostream>
#include <functional>

//double user_divide( double d1, double d2 ){
//    return d1 / d2;
//}

struct user_pair{
    double d1__;
    double d2__;
    double multiply(){
        return d1__ * d2__;
    }
};

int main(){

    using namespace std::placeholders;

    // bind:
    user_pair obj_1{ 10, 2 };
    auto bound_member_function = std::bind( &user_pair::multiply, _1 );        // return x.multiply()
    std::cout << bound_member_function( obj_1 ) << '\n';

    auto bound_member_data = std::bind( &user_pair::d1__, obj_1 );              // return obj_1.d1__;
    std::cout << bound_member_data() << '\n';


}

/* output

20
10

Process returned 0 (0x0)   execution time : 0.022 s
Press ENTER to continue.



*/
