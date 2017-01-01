/*
            Program support Utility
            ***********************

Non-local Jumps (in header <csetjmp>)

    > setjmp            : saves the context
    > longjmp           : jumps the specified location

*/
/// std::longjmp
//  void longjmp (std::jmp_buf env, int status)
//  Loads the execution context 'env' saved by a previous call to setjmp.
//  This function does not return. Control is transformed to the call site
//  of the macro setjmp that set up 'env'. That setjmp then returns the value,
//  passed as the status.
//
//

/// return value:
//  none

#include <iostream>
#include <csetjmp>

std::jmp_buf jump_buffer;

[[noreturn]] void f (int count){
    std::cout << "f (" << count << ") was called\n";
    std::longjmp( jump_buffer, count + 1 ); // setjump() will return count + 1

} // the end of void f(int)

int main (){

    volatile int count = 0;         // modified local in setjmp scope must be volatile

    if (setjmp( jump_buffer ) != 9) // equality against constant expression an if
        f( count++ );               // This will cause setjmp() to exit

}

/* output:

f (0) was called
f (1) was called
f (2) was called
f (3) was called
f (4) was called
f (5) was called
f (6) was called
f (7) was called
f (8) was called

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.

*/
