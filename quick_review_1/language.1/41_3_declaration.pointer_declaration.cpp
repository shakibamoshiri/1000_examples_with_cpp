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
#include <string>


int main(){
    // pointer declaration:

    int number = 10;
    int number2 = 20;

    int* ptr = &number;                 // pointer to int
    ptr = &number2;                     // okay pointer point is modifiable
    *ptr = 20 * 20;                     // okay data is also modifiable


    const int* ptr2 = &number;          // const-data pinter to int
    ptr2 = &number2;                    // okay pointer point is modifiable
    // error
//   *ptr2 = 20 * 20;                   // data is read-only


    int* const ptr3 = &number;          // non-const-data with const pointer to int
    // error
//    ptr3 = &number2;                    // pointer location is read-only
    *ptr3 = 10 * 10;                    // okay data is modifiable


    const int* const ptr4 = &number;    // const-data with const pointer to int
    // both data and pointer location is read-only
    // error
    // ptr4 = &number2;
    // *ptr4 = 20 * 20;


    // note that:
    const int* cptr = &number;
    // is as the same
    int const* cptr2 = &number;
    // in both cases the data is read-only
    // and the pointer location is not and it modifiable.
    // error
//    *cptr = 10 * 10;
//    *cptr2 = 10 * 10;
    //
    // but:
    cptr = &number2;    // okay
    cptr2 = &number2;   // okay, too

    // why is this okay?
    // because
    const int one = 1;
    // is as the same
    int const two = 2;

    // the only thing that make difference, is the place of asterisk(*)
    // if there is not const between the pointer-name and asterisk(*)
    // the pointer location is not const
    const int* /* there is no const */ ptr5;    // so it can point to another address of another variable

    // so between int and const we have no asterisk(*)
    // if you put, it is an error:

}
