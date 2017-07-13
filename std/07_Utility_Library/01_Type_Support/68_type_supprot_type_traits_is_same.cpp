/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

    Type Relationship
    > is_same               checks if two types are the same
    > is_base_of            checks if a type is derived form the other type
    > is_convertible        checks if at ype can be converted to the other type
*/
/// std::is_same
// template <class T, class U> struct is_same
//
// If T and U name the same type with the same const-volatile qualification
// provides the member constant value equal to 'true'. Otherwise value is false.

#include <iostream>
#include <type_traits>
#include <iomanip>


int main() {

    std::boolalpha( std::cout );

    endl( std::cout << std::is_same<int,int32_t>::value );      // true
    endl( std::cout << std::is_same<int,int64_t>::value );      // false
    endl( std::cout << std::is_same<int,signed int>::value );   // true

    endl( std::cout << std::setfill('*') << std::setw(10) << '*' );

    endl( std::cout << std::is_same<int, int>::value );         // true
    endl( std::cout << std::is_same<int,signed int>::value );   // true
    endl( std::cout << std::is_same<int,unsigned int>::value ); // false

    endl( std::cout << std::setfill('*') << std::setw(10) << '*' );

    endl( std::cout << std::is_same<char, char>::value );           // true
    endl( std::cout << std::is_same<char,signed char>::value );     // false
    endl( std::cout << std::is_same<char,unsigned char>::value );   // false

}
