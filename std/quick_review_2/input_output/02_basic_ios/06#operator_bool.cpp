/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::bool ( operator )
//  explicit operator bool() const
//  Evaluate stream







#include <iostream> // std::cout, std::ios
#include <fstream>


int main(){

    std::basic_ifstream< char > input_stream( "file" );

    if( input_stream ){ // using the operator bool( that means if open the file is success )
        // do something...
    } else {
        // do something...
    }

}
/**




**/
