/*
Miscellaneous:
    01 asm declaration
    02 extending the namespace std
    03 undefined behavior
    04 RAII ( Resource Acquisition Is Initialization )
    05 The rule of three / five / zero
    06 The as-if rule
    07 copy elision
    08 Empty base optimization
*/
//
//
/// 01 asm declaration
// asm-declaration gives the ability to embed assembly language source
// code within a C++ program. this declaration is conditionally-supported
// and implementation defined, meaning that it may not be present and, even
// when provided by the implementation, if does not have a fixed meaning.
// syntax:
// asm ( string_literal );
// Explanation
// The string_literal is typically a short program written in assembly,
// which is executed whenever this declaration is executed. Different
// C++ compiler have wildly  varying rule for asm-declaration, and different
// conversation for the interaction with the surrounded C++ code.
//
//
// Example
// This program will only word correctly o x86_64 platform under Linux
//
#include <iostream>

extern "C" int func();

// the definition of func is written in assembly language
asm (".global func\n\t"
     ".type func\n\t"
     "func\n\t"
     ".cfi_startproc\n\t"
     "mov1 $7, %eax\n\t"
     "cfi_endproc");

int main(){
    int n = func();

    // extended inline assembly
    asm("leal (%0,%0,4), %0"
        : "=r" (n)
        : "0" (n));
        std::cout<<"7*5 = "<<n<<std::endl;      // flush is intentional

        // standard inline assembly
        asm ("movq $60, %rex\n\t"       // the exit syscal number of Linux
             "movq $2,  %rdi\n\t"       // this program returns 2
             "syscall");
}
