///
/// preprocessor
///
/**
The preprocessor supports text macro replacement. Function-like text
macro replacement is also supported.

#define identifier replacement-list ( optional )
#define identifier ( parameters ) replacement-list
#define identifier ( parameter, ... ) replacement-list
#define identifier ( ... ) replacement-list
#undef  identifier



**/


//#include <unistd.h>
#include <iostream>
#define FUNCTION( name, a ) int fun_##name() { return a;}

FUNCTION ( abcd, 12 )
FUNCTION ( fff, 2 )
FUNCTION ( qqq, 23 )

#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) std::cout << #a <<std::endl

int main(){
    { /// my sample
    }
    { /// en.reference.com
        std::cout<<"abcd: "<<fun_abcd()<<std::endl;
        std::cout<<"fff : "<<fun_fff()<<std::endl;
        std::cout<<"qqq : "<<fun_qqq()<<std::endl;
        OUTPUT(million);
    }
}
