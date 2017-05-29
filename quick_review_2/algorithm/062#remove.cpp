/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// remove
//  Remove value from range.


int main(){

    std::string string{ "How are you today?" };

    std::string::iterator end_point = std::remove( begin( string ), end( string ),        // range of element
                 ' ' );

    std::cout << string << '\n';

    string.erase( end_point, string.end() );

    std::cout << string << '\n';

}

/* output

Howareyoutoday?ay?
Howareyoutoday?

Process returned 0 (0x0)   execution time : 0.014 s
Press ENTER to continue.


*/
