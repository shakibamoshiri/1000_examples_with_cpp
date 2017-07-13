/**

/// Expression
/// string literal
///
Syntax:

" ( unescaped_character | escaped_character )* "
L " ( unescaped_character | escaped_character )* "
u8 " ( unescaped_character | escaped_character )* "
u " ( unescaped_character | escaped_character )* "
U " ( unescaped_character | escaped_character )* "
prefix ( optional ) R " delimiter ( raw_character* ) delimiter "

Explanation
unescaped_character     - Any valid character
escaped_character       - See escape sequence
prefix                  - One of L, u8, u, U
delimiter               - A string made of any source character hut parentheses(), backslash\, and space' ' ( can
                          be empty, and at most 16 characters long )
raw_character           - Must not contain the closing sequence ) delimiter "


**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

char array1[] = "one" "two";
// same as:
char array2[] = {'o','n','e','t','w','o'};

const char* str1 = R"one(
                         Hello
                         World
                         )one";
// same as:
const char* str2 = "\nHello\nWorld\n";

int main(){
    std::cout<<array1<<'\n'<<array2<<std::endl;

    std::cout<<str1<<str2<<std::endl;
}













