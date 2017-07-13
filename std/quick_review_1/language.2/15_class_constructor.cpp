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
//  constructor

//  Constructor in a class can be:
//  1. explicit
//  2. constexpr
//  3. inline
//  4. friend
//  and nothing else
//
//  Explanation:

//  Constructors have no name and cannot be called directly. They are
//  invoked when initialization takes place, and they are selected --
//  according to the rule of initialization. The constructors without
//  "explicit" specifier are 'converting constructors'.

//  The constructors without "constexpr" specifier makes their type a
//  LiteralType.

//  Constructors that may be called without any argument are 'default
//  constructors'.( also if they have argument with default value, like C( int a = 0, int b = 0, and so on )

//  Constructors that take another object of the same type as the argument
//  are 'copy constructors' and 'move constructors'.

/******************/
#include <iostream>

class C {
private:
    const char* what;

public:
    C( const char* temp )
        : what( temp ) {}

    C() : what( "empty" ) {}

    const char* get_what(){ return what; };

};


int main(){

    C object;   // calls C() and 'what' becomes "empty"
    std::cout << object.get_what() << '\n';

    C obj2( "call the constructor" );   // initialize 'what' with 'temp' argument
    std::cout << obj2.get_what() << '\n';


}

/* output:
empty
call the constructor


*/
