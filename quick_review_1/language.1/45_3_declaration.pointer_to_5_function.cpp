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

int func (int) { // just for syntax resolution, and not usable
    static int count_calling = 0;

    ++count_calling;
    printf("who call me ? (%d)\n", count_calling);
}

int main(){
    // pinter to function
    func(0);        // first call, calls by itself

    // creates pointer to func
    int (*fptr0)(int) = func;       // no need to use & before the func like this: &func, but you can

    // by using l-value reference
    int (&fref0)(int) = func;

    // by using l-value reference through l-value pointer to function (fptr0)
    int (&fref1)(int) = *fptr0;     // asterisk(*) should be used



    fptr0(0);       // it is invoked directly through the pointer

    (*fptr0)(0);    // it is invoked through the function l-value

    fref1(0);       // it is invoked through l-value reference and also fref0


}
