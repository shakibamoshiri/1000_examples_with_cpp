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


int f_one( int one ){ return one; }



int ( *func                         // return type name
    ( int( *pf_one )( int ) )       // parameter name
    )
    ( int ) {                       // return argument

    return pf_one;

}



int main(){

    std::cout << f_one( 11 ) << '\n';           // 11

    std::cout << func( f_one )( 22 ) << '\n';   // 22

}
/* output:


*/
