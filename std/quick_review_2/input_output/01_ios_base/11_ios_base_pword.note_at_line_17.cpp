/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::pword
//  void* &pword( int index )
//  Get pointer element of extensible array


#include <iostream>

const int name_index = std::ios::xalloc(); // return int

// stores pointer in extensible array
void set_stream_name( std::ostream& stream, const char* name_of_stream ){   // change the std::ios& to std::ostream&
    stream.pword( name_index ) = const_cast< char* >( name_of_stream );
}

// custom manipulator that uses stored pointer
std::ostream& stream_name( std::ostream& output ){
    const char* name = static_cast< const char* >( output.pword( name_index ) );

    if( name ) output << name;
    else       output << "unknown";

    return output;
}


int main(){
    // pword example

    set_stream_name( std::cout, "standard output stream" );
    set_stream_name( std::cerr, "standard error stream" );

    std::cout << stream_name << '\n';
    std::cout << stream_name << '\n';

    std::cerr << stream_name << '\n';

    std::clog << stream_name << '\n';

}
/**




**/
