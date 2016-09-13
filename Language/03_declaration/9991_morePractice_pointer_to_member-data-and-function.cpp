/**
///

**/

#include <iostream>
#include <string>

struct S {
    int n;
    int f(){return n;}

    int S::* s;
    int (S::* sf)();
};

int main(){

    // creating an object form S
    S one;
    one.n = 10;         // 10 assigns to n
    one.s = &S::n;      // the address of S::n assigns to S::* s
    one.sf = &S::f;     // the address of S::f() assigns to S::* sf

    // with regular object
    std::cout<<one.n<<' '           // object.data
             <<one.*(one.s)<<' '    // object.*(object.pointer-member-data)
             <<(one.*(one.sf))()    // object.*(object.pointer-member-function)
             <<std::endl;

    S* two;
    two = &one;

    // with pointer object ( po )
    std::cout<<two->n<<' '              // pointer->data
             <<two->*(two->s)<<' '      // pointer->*(pointer->pointer-member-data)
             <<(two->*(two->sf))()      // pointer->*(pointer->pointer-member-function)
             <<std::endl;

    // creating pointer-member-data to data of struct S
    int S::* p = &S::n;

    // creating pointer-member data to pointer-member data of struct S
    int S::* S::* ps = &S::s;

    // creating pointer-member-function to pointer-member-function of S struct
    int (S::* S::* psf)() = &S::sf;

    // with regular object ( one )
    // print with pointer-member-data

    // one  : object                                    from S one;
    // two  : pointer                                   from S* two = &one;
    // *p   : pointer-to-member-data                    takes address &S::n
    // *ps  : pointer-to-pointer-to-member-data         tales address &S::s,  that points to &S::n
    // *psf : pointer-to-pointer-to-member-function     takes address &S::sf, that points to &S::f

    std::cout<<one.*p<<' '          // object.pointer-to-member-data
             <<one.*(one.*ps)<<' '  // object.*(object.*pointer-to-pointer-to-member-data)
             <<(one.*(one.*psf))()  // object.*(object.*pointer-to-pointer-to-member-function)
             <<std::endl;

    // with pointer-object ( two )
    std::cout<<two->*p<<' '             // pointer->*pointer-to-member-data
             <<two->*(two->*ps)<<' '    // pointer->*(pointer->*pointer-to-pointer-to-member-data)
             <<(two->*(two->*psf))()    // pointer->*(pointer->*pointer-to-pointer-to-member-function)
             <<std::endl;




}









