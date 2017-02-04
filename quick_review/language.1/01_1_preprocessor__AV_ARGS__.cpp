/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// preprocessor

#include <cstdio>

#define print(...) puts(#__VA_ARGS__)

int main(){
    print(this is test in how to use preporcessor macor); // print the sentence.
}


/*

__printf_chk
__strdup
__vsprintf_chk
__errno_location
__fxstat64
__fprintf_chk
__uflow
__xstat64
__ctype_b_loc
__snprintf_chk
__realpath_chk
__vfprintf_chk
__ctype_tolower_loc
__sprintf_chk
__fsetlocking
__strcat_chk
__libc_start_main
__overflow
__environ
__cxa_atexit
__stack_chk_fail
___tls_get_addr
__pthread_key_create
__gmon_start__
__COUNTER__ expanded inside directive with -fdirectives-only
__STDC_
__STDC_FORMAT_MACROS
__STDC_LIMIT_MACROS
__STDC_CONSTANT_MACROS
__VA_ARGS__
__has_include__
__has_include_next__
__VA_ARGS__ can only appear in the expansion of a C++11 variadic macro
__VA_ARGS__ can only appear in the expansion of a C99 variadic macro
__STDC__ 1
__cplusplus 201500L
__cplusplus 201402L
__cplusplus 201103L
__cplusplus 199711L
__ASSEMBLER__ 1
__STDC_VERSION__ 199409L
__STDC_VERSION__ 201112L
__STDC_VERSION__ 199901L
__STDC_UTF_16__ 1
__STDC_UTF_32__ 1
__STDC_HOSTED__ 1
__STDC_HOSTED__ 0
__OBJC__ 1
__TIMESTAMP__
__TIME__
__DATE__
__FILE__
__BASE_FILE__
__LINE__
__INCLUDE_LEVEL__
__COUNTER__
__has_attribute
__has_cpp_attribute
__STDC__
__float128
__gnu_cxx::__concurrence_lock_error
__gnu_cxx::__concurrence_unlock_error
...................................
...................................
...................................
...................................
strings /usr/bin/g++ | ack ^__

*/
