/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 3. exception
//


/******************/
#include <iostream>
/******************/


int main(){

    double d = 1e10;

    try {

        ( d > 1e7 ) ? throw std::overflow_error( "too big" ) : d;

    } catch ( std::overflow_error& ofe ){

        std::cerr << ofe.what() << std::endl;

    }


}

/* output:

too big

*/
