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

// enum that takes 16 bites
enum smallEnum : int16_t {
    A,B,C
};
enum color {
    red, yellow, green=20, blue
};
enum class altitude : char {
    high = 'H',
    low = 'L', // c++11 allows the extra comma
};
enum {
    d, e, f=e+2
};

// enumeration types (both scoped and unscoped ) can have overloaded operator's
std::ostream& operator<<(std::ostream& out, color c){
    switch(c){
        case red    : out<<"red";   break;
        case yellow : out<<"yellow";break;
        case green  : out<<"green"; break;
        case blue   : out<<"blue";  break;
        default     : out.setstate(std::ios_base::failbit);
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, altitude a){ // the type of altitude is char
    return out << static_cast<char>(a);
    // or
    // return out << char(a);
    // or
    // return out << (char)al;
}
int main(){

    color co = red;
    altitude a;
    a = altitude::low;

    std::cout<<"co  =   "<<co<<std::endl
             <<"a   =   "<<a<<std::endl
             <<"f   =   "<<f<<std::endl;

}












