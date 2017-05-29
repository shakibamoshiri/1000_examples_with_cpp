/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>


/// fill_if ( not in the algorithm library )
//  Fill range with value.
template< typename InputIterator, typename UnaryFunction, typename T >
UnaryFunction fill_if( InputIterator first, InputIterator last, UnaryFunction uf, const T& value ){

    while( first++ != last ) if( uf( *first ) ) *first = value;

    return uf;
}



int main(){

    std::string string( "[ a B c D e F g H ]" );
    fill_if( string.begin(), string.end(),
             []( const char& chr ){ return islower( chr ); },
             '-' );
    std::cout << string << '\n';


}

/* output

[ - B - D - F - H ]

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.


*/
