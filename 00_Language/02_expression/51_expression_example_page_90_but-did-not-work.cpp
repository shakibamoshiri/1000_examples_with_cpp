/**

/// Expression
/// string literal
/// user-defined literals ( since c++11 )

Allows integers, floating-point, character, and string literal to produce
objects of user-defined type by defining a user-defined suffix.

A user-defined literal is an expression of any of the following forms:
decimal-literal ud-suffix
octal-literal ud-suffix
hex-literal ud-suffix
binary-literal ud-suffix
function-constant exponent-part( optional ) ud-suffix
digit-sequence exponent-part ud-suffix
character-literal ud-suffix
string-literal ud-suffix
1-4     user-defined integer literals, such as 12_km
5-6     user-defined floating-point literals, such as 0.5_Pa
7       user-defined character literal, such as 'c'_X
8       user-defined string literal, such as, "abd"_L or u16"xyz"_M

**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

long double operator"" _w (long double);
std::string operator"" _w (const char16_t*, size_t);
unsigned operator"" _w (const char*);

int main(){

}













