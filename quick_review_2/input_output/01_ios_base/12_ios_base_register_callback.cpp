/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::register_callback
//  void register_callback( event_callback fn, int index )
//  Register event callback function



#include <iostream>
#include <fstream>

void test_fucntion( std::ios::event ev, std::ios_base& stream, int index ){
    switch( ev ){
    case stream.copyfmt_event:
        std::cout << "copyfmt_event\n";
        break;
    case stream.imbue_event:
        std::cout << "imbue_event\n";
        break;
    case stream.erase_event:
        std::cout << "erase_event\n";
        break;
    }
}

int main(){
    // stream callback

    std::ofstream filter;
    filter.register_callback( test_fucntion, 0 );
    filter.imbue( std::cout.getloc() );
}
/**

imbue_event
erase_event

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.




**/
