/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// function

#include <iostream>
#include <vector>

int i = 3;

auto f1(){ return i; }      // return type is int

const auto& f2(){ return i; }   // return type is const int&

decltype( auto ) f3(){ return i; }  // return type is int, same as decltype( i )

decltype( auto ) f4(){ return ( i ); }  // return type is int&, same as decltype( ( i ) )

int main(){


}
/* output:


*/
