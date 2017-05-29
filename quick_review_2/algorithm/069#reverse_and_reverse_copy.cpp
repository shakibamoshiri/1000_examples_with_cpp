/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
//#include <array>



/// reverse
/// reverse_copy
//  Reverse range.



int main(){

    std::string string{ "Howwwww Areeeee Youuuuuu Today?????" };

    std::reverse( string.begin(), string.end() );

    std::string string_2( string.size(), ' ' ) ;
    std::reverse_copy( string.begin(), string.end(), string_2.begin() );

    std::cout << string << '\n';
    std::cout << string_2 << '\n';

}

/* output

?????yadoT uuuuuuoY eeeeerA wwwwwoH
Howwwww Areeeee Youuuuuu Today?????

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.




*/
