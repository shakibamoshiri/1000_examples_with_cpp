/*

A review of iterator library


*/

/// move_iterator
//  Move iterator

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>


int main(){

    std::vector< std::string > vector_of_string{ "one", "two", "three" };
    std::vector< std::string > vos{ vector_of_string.size() };

    typedef std::vector< std::string >::iterator v_it;

    std::ostream_iterator< const std::string > output( std::cout, " " );
    std::copy( std::move_iterator< v_it >( vector_of_string.begin() ), std::move_iterator< v_it >( vector_of_string.end() ),
               vos.begin() );

    vector_of_string.clear();   // contains unspecified value; so clear it
    for( const std::string& str : vos ){
        std::cout << str << ' ';
    }
    std::cout << "\nvector_of_string: ";
    for( const std::string& str : vector_of_string ){
        std::cout << str << '\n';
    }

}
/* output

one two three
vector_of_string:



Process returned 0 (0x0)   execution time : 0.018 s
Press ENTER to continue.



*/
