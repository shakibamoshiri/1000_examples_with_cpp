/**
/// Enumeration Declaration
///
An enumeration is a distinct type whose value is restricted to one of
several explicitly named contents ("enumeration"). The values of the
contents are values of an integral type known as the underlying type of
the enumeration.
An enumeration is defined by enum-specifier, which appears in decl-specifier
-seq of the declaration syntax. The enum-specifier has the following syntax:

enum-key attribute(optional) identifier (optional) enum-base(optional) {
    enumeration list ( optional )
}
enum-key        one of 'enum', 'enum class', 'enum struct'

unscoped enumeration
enum name { enumerator = constexpr, enumerator = constexpr, ... }
enum name : type { enumerator = constexpr, enumerator = constexpr, ... }    since c++11
enum name : type; since c++11

**/
#include <iostream>
#include <string>

int main(){
    // each enumeration becomes a named constant of the enumeration's type
    // (that is name), visible in the enclosing scope, and can be used
    // wherever constants are required.
    enum Color { red, green, blue};
    Color t = red;
    switch(t){
        case red : std::cout<<"red"<<std::endl;
            break;
        case green : std::cout<<"green"<<std::endl;
            break;
        case blue : std::cout<<"blue"<<std::endl;
            break;
    }

    // If the first enumerator does not have an initializer, the associated value is zero (0).
    // For any other enumerator whose definition does not have an initializer, the associated
    // value is the value of the previous enumerator plus one 0, 0+1, 1+1, 2+1, ...
    enum stuff { a, b, c=10, d ,e=1, f, g=f+c};
    // a=0
    // b=1
    // c=10
    // d=11 ( 10+1)
    // e=1
    // f=2 ( 1+1)
    // g=12 ( 10 + 2 )

    enum number { one, two, three=20, four, five=50, six };
    (one==0) ? std::cout<<"okay\n" : std::cout<<"not\n";
    (six==51) ? std::cout<<"okay\n" : std::cout<<"not\n";

    enum access_t { read=1, write=2, exec=4};
    access_t rw = static_cast<access_t>(3);
    std::cout<<rw<<std::endl;
    (rw & read && rw & write) ? std::cout<<"okay\n" : std::cout<<"wrong\n";

    // The name of an unscoped enumeration may by omitted: such declaration
    // only introduces the enumerations into the enclosing scope
    enum { frist, second, third, fourth, fifth=33, sixth};
    sixth-fifth==1 ? std::cout<<"okay\n" : std::cout<<"wrong\n";

}












