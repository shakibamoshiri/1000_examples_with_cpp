/*
            Function Object
            ***************

1. Polymorphic Function Wrapper
    1.1 function
    ---------------------------
    1.2 mem_fncreates:
        Function template std::mem_fn generates wrapper objects for pointers to members,
        which can store, copy, and invoke a pointer to member. Both reference and pointer
        (including smart pointers) to an object cab be used when invoking a std::mem_fn.
        for more detail see the man website.

        member type:
            result_type
            argument_type
            first_argument_type
            second_argument_type



*/
///  std::user_allocator< std::function >
//
//   This specialization of std::user_allocator informs other library
//   components that all objects of type std::function support user-allocator
//   construction, even though they do not have a nested allocator_type.


#include <iostream>
#include <functional>

using SomeVoid = std::function< void (int) >;

class C {
private:
    SomeVoid void_func;

public:
    C( SomeVoid tempfunc = nullptr ) : void_func( tempfunc ){
        if( void_func == nullptr )
            void_func = std::bind( &C::default_func, this, std::placeholders::_1 );  // end of if statement

        void_func( 7 );
    }

    void default_func (int temp){ std::cout << temp << '\n'; }
};

void user_func (int temp){ std::cout << (temp + 1) << '\n'; }

int main (){

    C c1;

    C c2(user_func);

}

/* output for me:

7
8


*/
