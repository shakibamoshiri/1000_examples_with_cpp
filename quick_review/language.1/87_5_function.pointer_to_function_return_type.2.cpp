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


int f_one(){ return 11; }
int f_two(){ return 22; }


int ( *func ( int( *pf_one )(), int(*pf_two)() ) )() {

    if( pf_one() < pf_two() ) return pf_two;
    if( pf_one() > pf_two() ) return pf_one;

}



int main(){

    std::cout << func( f_one, f_two )() << '\n';    // 22

    std::cout << func( f_two, f_one )() << '\n';    // 22

}
/* output:


*/
