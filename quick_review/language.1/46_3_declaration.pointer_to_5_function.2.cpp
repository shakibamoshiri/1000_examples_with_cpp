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
/// expression

#include <iostream>
// #include <string>
// #include <iomanip>

const char* func (const char* str) { // no need to return const char*, just for syntax resolution, and not usable
    static int count_calling = 0;

    ++count_calling;

    printf("I know who calls me: '%s' --- (%d)\n",str, count_calling);
}

int main(){
    // pointer to function

    const char* (*fptr)(const char*) = func;
    fptr("*fptr");

    const char* (&fref0)(const char*) = func;
    fref0("&fref0");

    const char* (&fref1)(const char*) = *fptr;
    fref1("&fref1");
}
