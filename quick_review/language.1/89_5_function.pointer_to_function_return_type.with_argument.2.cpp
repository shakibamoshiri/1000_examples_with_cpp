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


int f_one( int one ){ return one - 1; }
int f_two( int two ){ return two - 2; }



int ( *func ( int( *pf_one )( int ) , int( *pf_two )( int )  ) ) ( int )
{

    return ( pf_one > pf_two ) ? pf_one : pf_two;

}



int main(){

    std::cout << func(  f_one, f_two )( 12 ) ;      // return 10


}
/* output:


*/
