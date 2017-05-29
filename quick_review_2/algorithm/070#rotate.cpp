/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// rotate
/// rotate_copy
//  Rotate left the element in range



int main(){

    std::string string{ "How Are You Today?" };

    std::rotate( string.begin(), std::find( string.begin(), string.end(), ' ' ) + 1 , string.end() );
    string.insert( string.find( '?' ) + 1 , " " );

    std::cout << string << '\n';    // not that it has a ' ' at the end:  'Are You Today? How '


}

/* output

Are You Today? How

Process returned 0 (0x0)   execution time : 0.014 s
Press ENTER to continue.


*/
