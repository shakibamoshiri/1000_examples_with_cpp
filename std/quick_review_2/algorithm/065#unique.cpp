/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// unique
//  Remove consecutive duplicate in range.


//char is_lower( const char chr ){
//    if( chr >= 'a' && chr <= 'z' )
//        return true;
//    else
//        return false;
//}
int main(){

    std::string string{ "Howwwww Areeeee Youuuuuu Today?????" };

    std::string::iterator end_point =
    std::unique( begin( string ), end( string ) );

    std::cout << string << '\n';

    string.erase( end_point, string.end() );

    std::cout << string << '\n';

}

/* output
How Are You Today?uuuuuu Today?????
How Are You Today?

Process returned 0 (0x0)   execution time : 0.022 s
Press ENTER to continue.


*/
