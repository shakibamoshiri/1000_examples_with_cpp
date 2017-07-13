/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::exchange
//
//  defined in header <utility>
//  Replaces the value of 'obj' with new_value and returns the old value of 'obj'.

#include <iostream>
#include <utility>
#include <vector>
#include <iterator>

class stream {
public:
    using flag_type = int;

    flag_type flags() const {return flags_; }

    // replaces flags_ by newf, and returns the old value
    flag_type flags( flag_type newf )
    { return std::exchange( flags_, newf ); }
private:
    flag_type flags_ = 0;
};

void f(){ std::cout << "f()" << '\n'; }

int main(){

    stream s;

    std::cout << s.flags() << '\n';
    std::cout << s.flags(4) << '\n';
    std::cout << s.flags() << '\n';

    std::vector< int > vector;

    // Since the second template parameter has a default value, it is possible
    // to use a braced-list as second argument. The expression below is
    // equivalent to std::exchange( vector, std::vector< int >{ 1, 2, 3, 4 } );
    std::exchange( vector, {1, 2, 3, 4} );

    std::cout << '\n';
    std::copy(begin( vector ), end( vector ), std::ostream_iterator< int >( std::cout, " " ) );

    void (*fptr)();

    // The default value of template parameter also makes possible to use a
    // normal function as second argument. The expression below is equivalent to
    // std::exchange( fptr, static_cast< void ( * )() >( f ) );
    std::exchange( fptr, f );

    std::cout << '\n';
    fptr();


}

/* output for me:
0
0
4

1 2 3 4
f()


*/
