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
/// 03 undefined behavior
//
//
// Return the entire program meaningless if certain rule of the language are violated
//
// Explanation
// The C++ standard precisely defines the observable behavior of every C++ program
// that does not fail into one of the following classes:
// - ill-formated
// - ill-formated no diagnostic required
// - implementation-defined behavior
// - unspecified behavior
// - undefined behavior
// * for more detail read the main site
//
//
//
// undefined behavior and optimization
// Because correct C++ programs are free of undefined behavior, compilers may
// produce unexpected results when a program that actually has UB is complied
// with optimization enabled.
// for example
int f(int x){
    return x+1 > x:     // either true or UB due to signed overflow
}
// may be complied as
int f(int x){
    return 1;
}


bool b;                 // uninitialized local variable
if (b)                  // UB access to uninitialized scaler ( not able to be scale )
    std::cout<<"b is true";
if( (!b)                // same as above
   std::cout<<"b is false';
// may be compiled to a program that prints both lines:
// b is true
// b is false
// or to a program that prints nothing


int table[4] = {}
bool exists_in_table ( int v){
    // return true in one of the first 4 iteration or UB due to out-of-bounds access
    for ( int i=0; i <= 4; i++ )
        if (table[i] ==  v ) return true;

    return false;

    // for i, 0 1 2 3 is not UB
    // but for [4] is UB
}
// this may be complied as
bool exists_in_table (int v){
    return true;
}


int *p = (*int)std::malloc(sizeof(int));
int *q = (*int)std::realloc(p, sizeof(int));
*p = 1;         // undefined behavior access to a pointer that was passed to realloc
*q = 2;
if ( p == q )   // undefined behavior access to a pointer that was passed to realloc
    printf("%d %d\n", *p, *q);
// this may print 1 2
