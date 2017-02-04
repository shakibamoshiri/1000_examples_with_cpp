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
/// 2. template
//


/******************/
#include <iostream>
/******************/






int main(){

    // first we see what we have
    /*
        template< parameter-list > declaration

        the parameter list may be:
            a non-type template parameter (i.e. int, char, ... )
            a type template parameter     (i.e. T, U, ...)
            a template template parameter (since c++17)

        Non-type can be:
            type name( optional )
            type name( optional ) = default;
            type ... name( optional )   since c++11

            for example:
            > std::nullptr_t        since c++11
            > integral type         any of them, char, std::size_t, ...
            > l-value reference
            > pointer type
            > pointer to member type
            > enumeration type

    Type template parameter can be:
        typename    name( optional )
        class       name( optional )
        typename|class  name( optional ) = default
        typename|class ...  name( optional )    since c++11

    Template template parameter:
    template< parameter-list > typename(c++17) | class      name( optional )
    template< parameter-list > typename(c++17) | class      name( optional ) = default
    template< parameter-list > typename(c++17) | class...   name( optional )

    */

}

/* output:



*/
