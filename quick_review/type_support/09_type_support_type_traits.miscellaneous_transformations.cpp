/*
    quick review:

    Language Support
        01. type support
        02. dynamic memory management
        03. error handling
        04. initializer-list
        05. variadic function
    **********************************

*/
/// 01. type support:
//
//  <type_traits>
//  miscellaneous transformations: enable_if

#include <iostream>
#include <typeinfo>

template< typename T, typename Enable = void >
struct S {
    S(){ puts( "primary template" ); }
};

template< typename T >
struct S< T, typename std::enable_if< std::is_floating_point< T >::value >::type > {
    S(){ puts( "specialized template" ); }
};



int main(){

    S< int > i;
    S< float > f;

}
/* output:

primary template
specialized template

*/
