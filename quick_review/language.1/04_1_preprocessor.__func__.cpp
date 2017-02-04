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

void function (){
    puts(__func__);
}

int main(){
    puts("print the name of the function through __func__: ");
    function();
}
