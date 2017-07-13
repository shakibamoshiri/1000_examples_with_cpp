

#include <iostream>
#include <utility>  // pair
#include <tuple>    // tie

std::pair< int, char > f1(){ return { 1, 'A' }; }
std::pair< int, char > f2(){ return std::make_pair( 2, 'B' ); }

int main(){

    int integer;
    char chr;

    std::tie( integer, chr ) = f1();
    std::cout << integer << ' ' << chr << '\n';

    std::tie( integer, chr ) = f2();
    std::cout << integer << ' ' << chr << '\n';



}
/* output

1 A
2 B

*/
