/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// rempve_copy and remove_copy_if
//  are the same
//  Remove value from range.


char is_lower( const char chr ){
    if( chr >= 'a' && chr <= 'z' )
        return true;
    else
        return false;
}
int main(){

    std::string string{ "How Are You Today?" };

    std::string::iterator end_point =
    std::remove_if( begin( string ), end( string ),        // range of element
                           is_lower  );

    std::cout << string << '\n';

    string.erase( end_point, string.end() );

    std::cout << string << '\n';

}

/* output


*/
