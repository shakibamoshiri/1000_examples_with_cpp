/**
/// Enumeration Declaration
/// Scoped enumeration
enum struct | class name { enumerator = constexpr, enumerator = constexpre, ... }
enum struct | class name : type { enumerator = constexpr, enumerator = constexpre, ... }
enum struct | class name;
enum struct | class name : type;

1)  declares a scoped enumeration type whose underlying type is int
    ( the keywords class and struct are exactly equivalent )
2)  Declares a scoped enumeration type whose underlying type is type
3)  Opaque enum declaration for an scoped enumeration whose underlying type is int
4)  Opaque emum declaration for an scoped enumeration whose underlying type is type
    ( opaque means: not clear to understand enough to see through or allow light through )


**/
#include <iostream>
#include <string>
enum class A : int { a, b ,c};
std::ostream& operator<<(std::ostream& out,enum A t){
    out<<(int)t<<' ';                        // okay with explicit cast
    return out << static_cast<int>(t);  // okay with static_cast
}

int main(){

    // error: a was not declared in this scope
    // std::cout<<a;
    A one = A::a;
    A two = A::b;
    A three  = A::c;
    // no match for operator <<
    // so we have to overload it
    std::cout<<one<<std::endl;
    std::cout<<two<<std::endl;
    std::cout<<three<<std::endl;

    enum class color { red, green, blue };
    color what = color::green;
    switch(what){
        case color::red : std::cout<<"red\n"; break;
        case color::green : std::cout<<"green\n"; break;
        case color::blue : std::cout<<"blue\n"; break;
    }
    // error: no scoped enum to int conversion
    // int n = r;
    int m = (int)what; // okay, explicit conversion
    int x = static_cast<int>(what);    // also okay,
    std::cout<<m<<' '<<x<<std::endl;



}












