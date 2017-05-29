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


int f_one(){ return 1; }
int f_two(){ return 2; }


void func( int( *pf_one )(), int( *pf_two )() ){

    std::cout << pf_one() << " and " << pf_two() << '\n';
}


int main(){

    func( f_one, f_two );   // pass two function

}
/* output:


*/
