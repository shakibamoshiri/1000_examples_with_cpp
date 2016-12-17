/*
            Program support Utility
            ***********************

Non-local Jumps (in header <csetjmp>)

    > setjmp            : saves the context
    > longjmp           : jumps the specified location

*/
/// std::setjmp
//  #define setjmp (env) /* implementation-defined */
//
//  Saves the current execution context into a variable 'env' of type
//  std::jum_buf. This variable can later be used to restore the current
//  execution context by the std::longjmp function. That is, when a call
//  to std::longjmp function is made, the execution containers at the
//  particular call site that constructed the std::jmp_buf variable passed
//  to std::longjmp.
//
//  NOTE:
//  The invocation of setjmp must appear only in one of the following contexts:
//  if, switch, while, do-while, for
//  If 'setjmp' appears in any other context, the behavior is undefined.
//
/// return value:
//  0 if the macro was called by the original code and the execution context was saved to 'env'.
//  Non-zero value if a non-local jump was just performed.
//  The return value is the same as passed to std::longjmp.

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
