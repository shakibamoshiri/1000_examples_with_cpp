/*

A review of initializer_list


*/



#include <iostream>
#include <initializer_list>
// #include <fstream>




int main(){

    std::initializer_list< int > init_list;
    init_list = { 1,2,3,4,5,6 };

    for( const int i : init_list )
        std::cout << i << ' ';

}
/* output


1 2 3 4 5 6
Process returned 0 (0x0)   execution time : 0.016 s
Press ENTER to continue.

*/
