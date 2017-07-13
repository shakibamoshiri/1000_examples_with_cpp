/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <iomanip>


/// adjacent_find
//  Finds adjacent element in range.


int main(){
    using cht = std::char_traits< char >;

    const char* c_string( "yellow color and green book" );  // ye[ll]ow and gr[ee]n and b[oo]k
    const int c_string_length = cht::length( c_string );

    const char* result_point = std::adjacent_find( c_string, c_string + c_string_length );
    int result_point_length = cht::length( result_point );

    if( result_point < c_string + c_string_length ){
        std::cout << "c_string: "
                  << c_string << '\n'
                  << "result  : "
                  << std::setw( c_string_length ) << result_point << '\n'
                  << "value   : "
                  << std::setw( c_string_length - result_point_length + 1 )  << *result_point << *result_point << '\n'
                  << "---------------------\n";
    }

    result_point = std::adjacent_find( result_point + 1, c_string + c_string_length );
    result_point_length = cht::length( result_point );

    if( result_point < c_string + c_string_length ){
        std::cout << "c_string: "
                  << c_string << '\n'
                  << "result  : "
                  << std::setw( c_string_length ) << result_point << '\n'
                  << "value   : "
                  << std::setw( c_string_length - result_point_length + 1 )  << *result_point << *result_point << '\n'
                  << "---------------------\n";
    }

    result_point = std::adjacent_find( result_point + 1, c_string + c_string_length );
    result_point_length = cht::length( result_point );

    if( result_point < c_string + c_string_length ){
        std::cout << "c_string: "
                  << c_string << '\n'
                  << "result  : "
                  << std::setw( c_string_length ) << result_point << '\n'
                  << "value   : "
                  << std::setw( c_string_length - result_point_length + 1 )  << *result_point << *result_point << '\n'
                  << "---------------------\n";
    }





}

/* output

c_string: yellow color and green book
result  :   llow color and green book
value   :   ll
---------------------
c_string: yellow color and green book
result  :                    een book
value   :                    ee
---------------------
c_string: yellow color and green book
result  :                         ook
value   :                         oo
---------------------



*/
