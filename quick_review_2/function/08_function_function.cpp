/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::function
//  function wrapper

#include <iostream>
#include <functional>

int div_2( int x ){
    return x / 2;
}

struct div_3{
    int operator()( int x ){
        return x / 3;
    }
};

struct div_5{
    int value__;
    int three() const {
        return value__ / 5;
    }
};

int main(){

    std::function< int( int ) > fo_1 = div_2;               // function
    std::function< int( int ) > fo_2 = &div_2;              // function pointer
    std::function< int( int ) > fo_3 = div_3();             // function object
    std::function< int( int ) > fo_4 = []( int x ){         // lambda function
        return x / 4;
    };
    std::function< int( int ) > fo_5 = std::negate< int >();    // standard function object


    std::cout << fo_1( 60 ) << '\n';
    std::cout << fo_2( 60 ) << '\n';
    std::cout << fo_3( 60 ) << '\n';
    std::cout << fo_4( 60 ) << '\n';
    std::cout << fo_5( 60 ) << '\n';

    // stuff with member
    std::function< int( div_5& ) > fo_6 = &div_5::value__;        // pointer to member data
    std::function< int( div_5& ) > fo_7 = &div_5::three;          // pointer to member function

    div_5 obj_1{ 60 };

    puts( "------------------" );
    std::cout << fo_6( obj_1 ) << '\n';
    std::cout << fo_7( obj_1 ) << '\n';

}

/* output

30
30
20
15
-60
------------------
60
12

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.

*/
