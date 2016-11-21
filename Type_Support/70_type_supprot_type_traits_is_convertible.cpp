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
/// std::is_convertible
// template<class From, class To> struct is_convertible {}
//
// If the return statement in the imaginary function definition "To" test() {return std::declval<From>();}
// is well-formated, (that is, if std::declval<From>() can be converted to "To" using implicit
// conversion), provides the member constant value equal to true. Otherwise value is false.


#include <iostream>
#include <type_traits>
#include <iomanip>

class A {};
class B : public A {};
class C {};

class D : C {};
int main() {

    std::boolalpha( std::cout );

    bool b2a = std::is_convertible<B*, A*>::value; // if inherited is public it is true
    bool a2b = std::is_convertible<A*, B*>::value;
    bool b2c = std::is_convertible<B*, C*>::value;
    bool c2c = std::is_convertible<C*, C*>::value;

    bool d2c = std::is_convertible<D*, C*>::value; // outputs is false

    std::cout << "b 2 a: " << b2a << '\n';  // true
    std::cout << "a 2 b: " << a2b << '\n';  // false
    std::cout << "b 2 c: " << b2c << '\n';  // false
    std::cout << "c 2 c: " << c2c << '\n';  // true

    std::cout << "d 2 c: " << d2c << '\n';  // false
}
