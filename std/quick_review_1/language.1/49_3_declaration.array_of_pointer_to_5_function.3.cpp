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

int func (int = 0){
    static int count = 0;

    ++count;
    printf("this function was called, ( %d )\n", count);
}

int three (int = 0){ puts("this is the third function call"); }



int main(){
    // pointer to function
    //
    // array of pointer to function

    int (*fptr_arr[])(int) = { func, func, three };

    int (**fptr2ptr)(int) = fptr_arr;

    (*fptr2ptr)(1);

    ++fptr2ptr;

    (*fptr2ptr)(1);

    ++fptr2ptr;

    (*fptr2ptr)(1);

    // call two func again
    (*(--fptr2ptr))(1);

    // calls three again
    (*++fptr2ptr)(1);






}
/* output:

this function was called, ( 1 )
this function was called, ( 2 )
this is the third function call
this function was called, ( 3 )
this is the third function call

*/
