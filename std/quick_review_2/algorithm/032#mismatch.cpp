/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>



/// mismatch
//  Returns the first position where the two range are different.


int main(){
    typedef std::char_traits< char > cht;

    const char* today    ( "How are you today? I am fine how about you?" );
    const char* yesterday( "How was you yesterday? I was fine how about you?" );

    const char* result_point_1 = std::mismatch( today, today + cht::length( today ), yesterday ).first;
    const char* result_point_2 = std::mismatch( today, today + cht::length( today ), yesterday ).second;

    std::cout << "result point_1: " << result_point_1
              << "\nresult point_2: " << result_point_2
              << "\nand both have: " << std::quoted( std::string( today, cht::length( today ) - cht::length( result_point_1 ) ) ) << '\n';

}

/* output

result point_1: are you today? I am fine how about you?
result point_2: was you yesterday? I was fine how about you?
and both have: "How "



*/
