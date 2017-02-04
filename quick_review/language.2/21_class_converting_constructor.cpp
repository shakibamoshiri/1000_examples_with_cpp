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
/// class
//  converting constructor


/******************/
#include <iostream>


struct S_cc {   // structure converting constructor
    const char* he = "";
    const char* she = "";
    const char* you = "";

    S_cc( const char* H )   // only one argument was allowed before c++11
        : he( H )
        { puts( "converting constructor with one argument" ); }
    S_cc( const char* H, const char* SH )//  after c++11
        : he( H ), she( SH )
        { puts( "converting constructor with two argument" ); }
    S_cc( const char* H, const char* SH, const char* Y )
        : he( H ), she( SH ), you( Y)
        { puts( "converting constructor with three argument" ); }

    void print(){
        puts( he );
        puts( she );
        puts( you );
    }
};



int main(){

    S_cc who = "jack";

    S_cc who_2 = { "jack", "Nancy" };   // with 2 argument

    S_cc who_3 = { "jack", "Nancy", "I do not know" };  // with 3 argument

}

/* output:

converting constructor with one argument
converting constructor with two argument
converting constructor with three argument


*/
