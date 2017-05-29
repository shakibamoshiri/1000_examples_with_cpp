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


int ( *pf_list [2] )() = { f_one, f_two };

int main(){

    // having no error but incorrect way in use
    std::cout << pf_list[ 0 ] << ' '
              << pf_list[ 1 ] << '\n';


    // okay correct way
    std::cout << pf_list[ 0 ]() << ' '
              << pf_list[ 1 ]() << '\n';



}


/* output:


*/
