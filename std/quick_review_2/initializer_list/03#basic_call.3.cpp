/*

A review of initializer_list


*/



#include <iostream>
// #include <iterator>
// #include <fstream>



int main(){

    for( const int& i : { 1,2,3,4,5,6,7,8 } )   // also an initializer_list object
        std::cout << i << ' ';

}
/* output

1 2 3 4 5 6 7 8
Process returned 0 (0x0)   execution time : 0.015 s
Press ENTER to continue.


*/
