/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>



/// equal
//  Tests whether the elements in two ranges are equal or not.


int main(){
    typedef std::char_traits< char > cht;

    const char* today    ( "How are you today?" );
    const char* yesterday( "How was you yesterday?" );

    bool today_equals_yesterday = std::equal( today, today + cht::length( today ),
                                             yesterday, yesterday + cht::length( yesterday ) );
    if( today_equals_yesterday )
        std::cout << "okay both are equal\n";

    yesterday = "How are you today?";

    today_equals_yesterday = std::equal( today, today + cht::length( today ),
                                             yesterday, yesterday + cht::length( yesterday ) );
    if( today_equals_yesterday )
        std::cout << "okay both are equal\n";





}

/* output

okay both are equal

Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.




*/
