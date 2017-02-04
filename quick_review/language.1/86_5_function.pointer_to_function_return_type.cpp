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


int ( *func ( int( *pf_one )() ) )() {

    return pf_one;

}



int main(){

    // having no error but wrong syntax ( it always return 1 )
    std::cout << func( f_one ) << ' '
              << func( f_two ) << '\n';

    // okay and correct syntax
    std::cout << func( f_one )() << ' '
              << func( f_two )() << '\n';   // 11 22


}
/* output:


*/
