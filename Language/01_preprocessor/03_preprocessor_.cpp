///
/// preprocessor
///
/// source file inclusion
/**
#include <filename>
#include "filename" /// belonging user
__has_include ("filename")
__has_include (<filename>)

Any preprocessing token ( macro constants or expression ) are permitted as
argument to #include and __has_include ( since c++17 ) as long as they expend
to a sequence of character surrounded by < > or " ".

**/
#if __has_include(<opstional>)
#include <optional>
#define have_optional 1
#elif __has_include(<experimental/optional>)
#include <experimental/optional>
#   define have_optional 1
#   define experimental_optional 1
#else
#   define have_optional 0
#endif // __has_include

#ifndef TEXT
#include <iostream>

int main(){
    { /// my sample
    }
    { /// en.reference.com
        #define TEXT "hello, World"
        #include __FILE__
        #define TEXT "Hello again"
        #include __FILE__


    }

}
#else
    std::cout<<TEXT<<'\n';
    #undef TEXT
#endif // TEXT
