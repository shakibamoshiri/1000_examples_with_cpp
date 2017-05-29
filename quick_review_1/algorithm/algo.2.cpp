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
/// for_each( InputIterator, InputIterator, UnaryFunction ){}

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

    /***************************************************/
    struct Sort {


        struct Binary {
            void operator()( const char* cstring ){
                std::cout << cstring << '\n';
            }
        }binary;

        struct Bubble {
            void operator()( const char* cstring ){
                std::cout << cstring << '\n';
            }

        }bubble;

        struct Quick {
            void operator()( const char* cstring ){
                std::cout << cstring << '\n';
            }
        }quick;


    }sort;
    /***************************************************/
    struct Calcualte {

        struct Minimum {
            void operator()( const char* cstring ){
                std::cout << cstring << '\n';
            }
        }min;
        struct Maximum {
            void operator()( const char* cstring ){
                std::cout << cstring << '\n';
            }
        }max;
        struct Average {
            void operator()( const char* cstring ){
                std::cout << cstring << '\n';
            }
            void operator()(){
                std::cout << "you called help function for algo.calc.ave\n\n";
                std::cout << "what is Average algorithm?\n";
                std::cout << "this algorithm calculate the average of a list of numbers.\n"
                          << "for example if you have { 1, 2, 3 } after calling the function\n"
                          << " it would be 3\n"
                          << " simple the function sum of each number and then divide it by size\n"
                          << "of the list. and here sum( 1, 2, 3 ) is divide by 3\n";
            }
        }ave;

    }calc;
    /***************************************************/

}algo;



int main(){

    /*
        the main object is:
            algo

        the middles objects are:
            print
            calculate
            sort
            do

        the finally object are:
            print:
                simple
                reverse

            calculate:
                sum
                min
                max
                ave

            sort:
                binary
                quick
                bubble
                merge

            do:
                join
                split
                reverse
                push
                pop
    */

    algo.sort.binary( "this is binary sort" );
    algo.sort.quick( "this is quick sort" );
    algo.sort.bubble( "this is bubble sort" );

    algo.calc.ave( "this is average algorithm" );
    algo.calc.max( "this is maximum algorithm" );
    algo.calc.min( "this is minimum algorithm" );

    algo.calc.ave();    // with out any argument calls help for this algorithm


}

/* output for me:

this is binary sort
this is quick sort
this is bubble sort
this is average algorithm
this is maximum algorithm
this is minimum algorithm

*/
