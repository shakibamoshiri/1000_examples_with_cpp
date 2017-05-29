/*
            Algorithm
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********

Algorithm library has nine ( 9 ) types of operations:

    1)  Non-modifying sequence operations
    2)  Modifying sequence operations
    3)  Partitions operation
    4)  Sorting operations
    5)  Binary search operations( on sorted range )
    6)  Set operations ( on sorted range )
    7)  Heap operations
    8)  Minimum / Maximum operations
    9)  Numeric operations

*/
///

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <typeinfo>


// Objected Oriented Programming Style more specific

struct Algorithm {

    // foreach: gets a containers and run function for each element
    struct ForEach {
        template< class InputIterator, class UnaryFunction >
        UnaryFunction operator()( InputIterator first, InputIterator last, UnaryFunction function ){

            while( first != last ){
                function( *first );
                ++first;
            }
            return function;

        }

    }foreach;

    // join: get a containers and joins the with 'thread' and returns a string
    struct Join {
        template< typename InputIterator >
        std::string operator()( InputIterator first, InputIterator last, std::string thread ){

            // test the contents of the containers to see what it is
            decltype( first ) type;
            if( typeid( *type ) == typeid( int ) ) std::cout << "content is int\n";
            if( typeid( *type ) == typeid( float ) ) std::cout << "content is float\n";
            if( typeid( *type ) == typeid( char ) ) std::cout << "content is char\n";
            if( typeid( *type ) == typeid( const char* ) ) std::cout << "content is const char*\n";
            // if the contents was not a string type
            // first we should convert the contents to string
            // then continuing to rest of process below.

            std::string result;
            while( first != last ){

                result += *first;
                ++first;

                if( first != last )
                    result += thread;
            }

            return result;
        }

    }join;


}algo;



int main(){

    std::vector< const char* > vector{ "one", "two", "three", "four", "five" };

    std::string result_of_join = algo.join( vector.begin(), vector.end(), " + " );

    std::cout << result_of_join;

}

/* output for me:

content is std::string
one + two + three + four + five


*/
