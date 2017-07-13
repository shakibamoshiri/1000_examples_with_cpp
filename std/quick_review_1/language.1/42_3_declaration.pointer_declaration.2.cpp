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

    int* iptr = &number;                // pointer to int

    int* const* icptr = &iptr;          // non-cosnt pointer to const pointer to non-const int
                                        // (     int*      )    (  const*  )  =  &iptr;


    int& iref = *iptr;                  // reference is bound to a l-value (it returns 10)

    struct S { int one; };              // a structure that has a integer data-member
    S s;

    int* iptr2data_member = &s.one;     // okay pointer to a integer(to the int) that is a member of S

    int S::* iptrdata = &S::one;        // okay pointer to member one

    // NOTE:
    // the unary operator *
    // returns the l-value expression

}
