/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 2. template
//  template argument lists


/******************/
#include <iostream>
#include <utility>  // std::pair
#include <functional>
/******************/


template< typename... PPE >
void print( std::pair< PPE... > pair ){

    std::cout << pair.first << ' ' << pair.second << '\n';
}

int main(){

    print( std::pair< int, int >( 1, 1 ) );             // PPE...       is expanded to std::pair< int, int > pair
    print( std::pair< int, char >( 1, 'c' ) );          // "            "              std::pair< int, char > pair
    print( std::pair< char, int >( 'c', 1 ) );          // "            "              std::pair< char, int > pair

    print( std::pair< const char*, const char* >( "char* 1", "char* 2" ) ); // PPE...   is expanded to std::pair< const char*, const char* > pair

}

/* output:



*/
