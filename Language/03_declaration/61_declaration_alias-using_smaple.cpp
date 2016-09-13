/**
Type alias, alias template (since c++11)
Type alias is name that refers to previously defined type ( similar to typedef )
Alias template is a name that refers to a family of type.

Syntax:
Alias declaration are declarations with the following syntax:
1. using identifier attribute ( optional ) type-id;

2. template<template parameter list>
using identifier attribute ( optional ) = type-id;

**/

#include <iostream>
#include <string>
#include <ios>
#include <type_traits>

// type alias, identical to
// typedef std::ios::base::fmtflags flags
using flags = std::ios_base::fmtflags;

// type name 'flags',now denotes a type:
flags f1  = std::ios_base::dec;

// type alias, identical (similar) to
// typedef void (*func)(int, int);
using func = void (*)(int,int);

//the name 'func' now denotes a pointer to function:
void test(int,int){}
func fn = test;

/* template type alias */
template <class T> using ptr = T*;
// the name 'ptr<T>' is new an alias for pointer to T
ptr<int> x;

// type alias used to hide a template parameter
template<class CharT> using mystring =
    std::basic_string<CharT,std::char_traits<CharT>>;
mystring<char> str;

// type alias can be introduced a member typedef name
template<typename T>
struct Container {
    using value_type = T;
};

// type alias can be used in generic programming
template<typename Container>
void fu2 (const Container& c){
    typename Container::value_type n;
}

// type alias used to simplify the syntax of std::enable_if
template<typename T> using Invoke =
    typename T::type;
template<typename Condition> using EnableIf =
    Invoke<std::enable_if<Condition::value>>;
template<typename T, typename = EnableIf<std::is_polymorphic<T>>>
int fpoly_only(T t) {return 1;}

struct S {virtual ~S() {} };

int main(){
    Container<int> c;
    fu2(c) ;         //  container::value_type will be int in this function

//    fpoly_only(c);    // error, enable_if prohibits this

    S s;
    fpoly_only(s);  // okay, enable_if allows this
}









