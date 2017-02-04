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
/// std::istream_iterator
//  It is a single pass iterator that reads successive objects of type T
//  from the std::basic_istream object for which it was constructed by,
//  calling the appropriate operator >>.

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

// this example can be useful for paring command line
int main(){

    std::string string =  "--one 1 1 1";

    std::istringstream iss( string ); // reading from a string

    std::vector< std::string > vector_of_string
    // correct and complete syntax:
    ( (std::istream_iterator< std::string >( iss )), (std::istream_iterator< std::string >()) );
    // incomplete syntax:
    // ( std::istream_iterator< std::string >( iss ), std::istream_iterator< std::string >() );

    // more readable syntax:
    // std::copy( std::istream_iterator< std::string >( iss ),
    //            std::istream_iterator< std::string >(),
    //            std::back_insert_iterator< std::vector< std::string > >( vector_of_string ) );

    std::cout << vector_of_string[ 0 ] << '\n';
    std::cout << vector_of_string[ 1 ] << '\n';
    std::cout << vector_of_string[ 2 ] << '\n';
    std::cout << vector_of_string[ 3 ] << '\n';
    std::cout << vector_of_string.size() << '\n';


}

/* output for me:



*/
