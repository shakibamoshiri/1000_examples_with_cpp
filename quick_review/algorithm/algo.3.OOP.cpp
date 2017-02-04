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



// Objected Oriented Programming Style more specific

class Algorithm {

    class Make {
        // foreach: gets a containers and run function for each element
        struct ForEach {
            void operator()( ){
                std::cout << "algo.foreach() help:\n";
            }
        };

        // split
        struct Split {
            void operator()( ){
                std::cout << "algo.split() help:\n";
            }
        };

        // Join
        struct Join {
            void operator()( ){
                std::cout << "algo.join() help:\n";
            }
        };
    public:
        ForEach foreach;
        Split   split;
        Join    join;

    };

    class Sort {

        struct Binary {
            void operator()( ){
                std::cout << "algo.sort.binary () help:\n";
            }
        };
        struct Quick {
            void operator()( ){
                std::cout << "algo.sort.quick( ) help:\n";
            }
        };
        struct Bubble {
            void operator()( ){
                std::cout << "algo.sort.bubble () help:\n";
            }
        };

    public:
        Binary  binary;
        Quick   quick;
        Bubble  bubble;

    };

    class Print {};
    class Search {};
    class Calculate {};

public:

    // interface
    Make        make;
    Sort        sort;
    Print       print;
    Search      search;
    Calculate   calc;


}algo;



int main(){

    // using class and interface
    algo.make.foreach();
    algo.make.split();
    algo.make.join();

    algo.sort.binary();
    algo.sort.quick();
    algo.sort.bubble();

}

/* output for me:

algo.foreach() help:
algo.split() help:
algo.join() help:
algo.sort.binary () help:
algo.sort.quick( ) help:
algo.sort.bubble () help:

*/
