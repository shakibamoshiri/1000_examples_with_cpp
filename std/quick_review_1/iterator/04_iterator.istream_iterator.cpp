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
#include <iterator>


int main(){

    std::istringstream iss( "--one 1 1 1" );

    // base of reading is std::string
    std::copy( std::istream_iterator< std::string >( iss ),
               std::istream_iterator< std::string >(),
               std::ostream_iterator< std::string >( std::cout, ", " ) );

    puts( "" );

    iss.clear();    // clean the end of the stream
    iss.seekg(0);   // goes to the beginning again.

    // base of reading is character
    std::copy( std::istream_iterator< char >( iss ),
               std::istream_iterator< char >(),
               std::ostream_iterator< char >( std::cout, ", " ) );



}

/* output for me:



*/
