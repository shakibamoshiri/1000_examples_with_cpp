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

struct X {
    enum direction {left='l', right='r'};
};

class W {
private:
    enum { one, two, three };
public:
    void printw (){
        std::cout<<this->one<<' '
                 <<this->two<<' '
                 <<this->three;
    }
};

class S {
private:
    enum color { red, green, blue };
public:
    void printS (){
        std::cout<<this->red<<' '           // this->red is okay
                 <<this->color::green<<' '  // this->color::green is okay
                 <<color::blue;             // color::blue is okay
    }
};
int main(){
    // When an unscoped enumeration is a class member, its enumerators
    // may by accessed using class member ( a.b ) or access class
    // pointer member ( a->b ). Also after c++11 ( object::class::enum ) is accessed.

    X x;
    X* p = &x;
    std::cout<<(char)x.left<<' '<<(char)x.right<<std::endl;                         // okay
    std::cout<<(char)p->left<<' '<<(char)p->right<<std::endl;                       // okay
    std::cout<<(char)X::direction::left<<' '<<(char)X::direction::right<<std::endl; // okay since c++11
    std::cout<<(char)X::left<<' '<<(char)X::right<<std::endl;                       // okay since c++11

    W w;
    W* pw = &w;
    w.printw();
    // one is private
    // pw->one;
    pw->printw();
    void (W::* pp)() = &W::printw;
    (w.*pp)();
    (pw->*pp)();
    std::cout<<std::endl;
    S s;
    s.printS();

}












