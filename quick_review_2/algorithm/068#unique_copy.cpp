/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// unique_copy
//  Remove consecutive duplicate in range.


char is_lower( const char ch_1, const char ch_2 ){
    if( ch_1 == ch_2  )
        return true;
    else
        return false;
}
int main(){

    std::string string{ "Howwwww Areeeee Youuuuuu Today?????" };

    std::string::iterator end_point =
    std::unique( begin( string ), end( string ),        // range of element
                 is_lower );

    std::cout << string << '\n';

    string.erase( end_point, string.end() );

    std::cout << string << '\n';

}

/* output


*/
