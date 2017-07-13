/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::move

//  std::move is used to indicate that an object 't' may be moved from,
//  i.e. allowing the efficient transfer or resources from 't' to another object.
//  t:      the object to be moved
//  return: static_cast< typename std::remove_reference< T >::type&& >( t )
//  for more detail see the main website



#include <iostream>
#include <utility>
#include <string>
#include <vector>

int main(){

    std::string string = "hello";
    std::vector< std::string > v_string;

    // used the push_back( const T& ) overload, which means
    // we will incur the cost of copying string
    v_string.push_back( string );
    std::cout << "after copy, string is\"" << string << "\"\n";

    // uses the r-value reference push_back( T&& ) overload
    // which means no string will be copied; instead, the contents
    // of string will be moved into the vector. This is less
    // expensive, but also means string might now be empty
    v_string.push_back( std::move( string ) );
    std::cout << "after move, string is:\"" << string << "\"\n";

    std::cout << "the contents of the vector are: \""
              << v_string[ 0 ]
              << "\", \""
              << v_string[ 1 ]
              << "\"\n";
    // string move assignment operator is often implemented as swap
    // in this case, the moved-from object is NOT empty
    std::string string_2 = "good-bye";
    std::cout << "before move from string_2, it is: "
              << string_2
              << '\n';
    v_string[ 0 ] = std::move( string_2 );      // swap v_string[ 0 ] with string_2!!! why I do not know!!!

    std::cout << "after move from string_2, it is: "
              << string_2
              << '\n';
}
/* output for me:

after copy, string is"hello"
after move, string is:""
the contents of the vector are: "hello", "hello"
before move from string_2, it is: good-bye
after move from string_2, it is: hello

*/
