

#include <iostream>
//#include <utility>  // pair
#include <tuple>    // tie

template< typename Tuple, std::size_t N > // primary
struct Printer {
    static void print_tuple( const Tuple& tup ){
        Printer< Tuple, N - 1 >::print_tuple( tup );
        std::cout << ' ' << std::get< N - 1 >( tup );
    }
};
template< typename Tuple >              // specialized
struct Printer< Tuple, 1 > {
    static void print_tuple( const Tuple& tup ){
        std::cout << std::get< 0 >( tup );
    }
};

template< typename... ARG >
void print_tuple( const std::tuple< ARG... >& tup ){
    Printer< decltype( tup ), sizeof...( ARG ) >::print_tuple( tup );
}

int main(){

    std::tuple< int, char, float > tuple( 1, 'A', 1.1 );
//    std::cout << std::get< 0 >( tuple ) << ' '
//              << std::get< 1 >( tuple ) << ' '
//              << std::get< 2 >( tuple ) << '\n';
    print_tuple( tuple);
}
