/*
            Iterator
            ********
written and tested on code::block 16.01
                      Ubuntu      16.01
            ********


There are six type of iterator:
    InputIterator
    OutputIterator
    ForwardIterator
    BidirectionalIterator
    RandomAccessIterator
    ContiguousIterator  (since c++17)

*/
/// std::front_insert_iterator ( OutputIterator )
//  It appends to a container
//  Instead of front_insert_iterator, there is a convenience function template named
//  front_inserter

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

int main(){

    std::vector< std::string > command_line = { "--one 1 1 1", "--two 2 2 2", "--three 3 3 3" };

    std::vector< std::string > vector_of_string;

    /// note; that is need to have push_front function
    /// and if there is no push_front function give you error
    /// like below: because vector has not push_front function
    std::copy( command_line.begin(),
               command_line.end(),
               std::front_insert_iterator< std::vector< std::string > >( vector_of_string ) ); // simplified with std::front_inserter
               // std::front_inserter( vector_of_string ) );

    std::cout << vector_of_string[ 0 ] << '\n';
    std::cout << vector_of_string[ 1 ] << '\n';
    std::cout << vector_of_string[ 2 ] << '\n';

}

/* output for me:



*/
