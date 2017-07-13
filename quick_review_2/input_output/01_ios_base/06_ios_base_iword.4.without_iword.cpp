/*

A review of abstraction section from cplusplus.com

*/
/// ios
//
/// iword
//  long& iword( int index )
//  Get integer element of extensible array

#include <iostream>

// custom manipulator with pre-stream static data
std::ostream& counter ( std::ostream& output ){
    static int count = 0;
    ++count;
    if( count % 2 == 0 )
        return output << "odd number";
    else
        return output << "even number";
}

int main(){
    // internal extensible array

    for( int stuff = 0; stuff < 20; ++stuff )
        std::cout << counter << " : " << stuff << '\n';
}
/**



**/
