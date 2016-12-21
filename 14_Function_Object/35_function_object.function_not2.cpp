/*
            Function Object
            ***************

4. Function objects (build-in)
    4.1 arithmetic  operations

    --------------------------------------------
    4.2 comparison  operations

    --------------------------------------------
    4.3 logical     operations

    --------------------------------------------
    4.4 bitwise     operations

    --------------------------------------------
    4.5 negators    operations

        unary_negatew       rapper function object returning the complement of the unary predicate it holds
        binary_negate       wrapper function object returning the complement of the binary predicate it holds
        not1                constructs custom std::unary_negate object
        not2                constructs custom std::binary_negate object
*/
/// not2


#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

struct old_same : std::binary_function< int, int, bool >{
    bool operator()( int arg1, int arg2 ) const { return arg1 == arg2; }
};

struct new_same {
    bool operator()( int arg1, int arg2 ) const { return arg1 == arg2; }
};

bool same_function( int arg1, int arg2 ){ return arg1 == arg2; }


int main() {
    std::vector< int > v1 {0, 1, 2};
    std::vector< int > v2 {2, 1, 0};
    std::vector< bool > v3( v1.size() );

    puts( "negating a binary function:" );
    std::transform( v1.begin(), v1.end(),
                   v2.begin(),
                   v3.begin(),
                   std::not2( old_same() ) );
    // and print:
    std::cout << std::boolalpha;
    std::size_t index = 0;
    while( index < 3 ){
        std::cout << v1[ index ] << ' '
                  << v2[ index ] << ' '
                  << v3[ index ] << ' '
                  << std::endl;

    ++index;
    }

    puts( "negating a standard function:" );
    std::transform( v1.begin(), v1.end(),
                   v2.begin(),
                   v3.begin(),
                   std::not2( std::equal_to< int >() ) );
    // and print:
    index = 0;
    while( index < 3 ){
        std::cout << v1[ index ] << ' '
                  << v2[ index ] << ' '
                  << v3[ index ] << ' '
                  << std::endl;

    ++index;
    }

    puts( "negating a std::function:" );
    std::transform( v1.begin(), v1.end(),
                    v2.begin(),
                    v3.begin(),
                    std::not2( std::function< bool( int, int ) >( new_same() ) ) );
    // and print:
    index = 0;
    while( index < v1.size() ){
        std::cout << v1[ index ] << ' '
                  << v2[ index ] << ' '
                  << v3[ index ] << ' '
                  << std::endl;

    ++index;
    }

    puts( "negating a std::reference_wrapper:" );
    std::transform( v1.begin(), v1.end(),
                    v2.begin(),
                    v3.begin(),
                    std::not2( std::ref( same_function ) ) );
    // and print:
    index = 0;
    while( index < v1.size() ){
        std::cout << v1[ index ] << ' '
                  << v2[ index ] << ' '
                  << v3[ index ] << ' '
                  << std::endl;

    ++index;
    }

}


/* output for me:

negating a binary function:
0 2 true
1 1 false
2 0 true
negating a standard function:
0 2 true
1 1 false
2 0 true
negating a std::function:
0 2 true
1 1 false
2 0 true
negating a std::reference_wrapper:
0 2 true
1 1 false
2 0 true

*/











