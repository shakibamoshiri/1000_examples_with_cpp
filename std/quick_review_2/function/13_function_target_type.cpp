/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::function::operator () parentheses
//  call target

#include <iostream>
#include <functional>
#include <typeinfo>


int plus ( const int x, const int y ){
    return x + y;
}

int main(){

    std::function< int( int, int ) > user_plus = plus;
    std::function< int( int, int ) > std_plus  = std::plus< int >();

    std::cout << "pointer as target:\n" << std::boolalpha;
    std::cout << ( user_plus.target_type() == typeid( int (*)( int, int ) ) ) << '\n';
    std::cout << ( std_plus.target_type() == typeid( int (*)( int, int ) ) ) << '\n';

}

// why is std_plus false?
// because a struct type + ( operator() ) and not a pointer to function
/* output

pointer as target:
true
false

Process returned 0 (0x0)   execution time : 0.014 s
Press ENTER to continue.


*/
