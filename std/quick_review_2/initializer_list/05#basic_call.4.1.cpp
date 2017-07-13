/*

A review of initializer_list


*/



#include <iostream>
#include <vector>
// #include <fstream>


//void function_1( std::initializer_list< int > init_list ){
//    std::cout << __func__ << " was called with initializer_list\n";
//}
void function_1( std::vector< int > vector ){
    std::cout << __func__ << " was called with vector\n";
}

int main(){

    function_1( { 1,2,3 } );
    function_1( { 1,2,3 } );

}
/* output

function_1 was called with vector
function_1 was called with vector

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.


*/
