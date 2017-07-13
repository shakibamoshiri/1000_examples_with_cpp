/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::integer_sequence

//  defined in header <utility>

//  The class template std::integer_sequence represents a compile-time
//  sequence of integers. When used as an argument to a function, the
//  parameter pack, 'Ints' can be deduced and used in pack expression.

// helper template
// index_sequence
// index_sequence_for
// make_index_sequence



#include <iostream>
#include <utility>
#include <tuple>
#include <array>

// coverts an array into a tuple
template< typename Array, std::size_t... Size >
decltype( auto ) array_2_tuple_imp( const Array& arr, std::index_sequence< Size... > )
{ return std::make_tuple( arr[ Size ]... ); }

template< typename T, std::size_t N, typename Indexes = std::make_index_sequence< N > >
decltype( auto ) array_2_tuple ( const std::array< T, N >& arr )
{ return array_2_tuple_imp( arr, Indexes() ); }

// pretty-print a tuple (from http://stackoverflow.com/a/6245777/273767 )
template< class Ch, class Tr, class Tuple, std::size_t... ls >
void print_tuple_imp( std::basic_ostream< Ch, Tr >& os, const Tuple& tup, std::index_sequence< ls... > )
{
    using swallow = int [];
    (void) swallow{ 0, ( void ( os << ( ls == 0 ? "" : ", " ) << std::get< ls >( tup ) ), 0 )... };
}

template< class Ch, class Tr, class... Args >
decltype( auto ) operator<<( std::basic_ostream< Ch, Tr >& os, const std::tuple< Args... >& tup )
{
    os << "(";
    print_tuple_imp( os, tup, std::index_sequence_for< Args... >{} );
    return os << ")";
}



int main(){

    std::array< int, 4 > array = {1, 2, 3, 4};

    // converts an array to a tuple
    auto tuple = array_2_tuple( array );
    static_assert( std::is_same< decltype( tuple ),
                   std::tuple< int, int, int, int > >::value,
                   "" );

    // print it to cout
    std::cout << tuple;

}
/* output for me:



*/
