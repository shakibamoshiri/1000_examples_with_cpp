/*

A review of algorithm library

Min / Max:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// max
//  return the largest

// return is: maximum value


bool BinaryFunction( int right, int left ){
    return right < left;
}

int main(){

    std::cout << std::max( -1, 3 ) << '\n';
    std::cout << std::max( { -1, 3 } ) << '\n';
    std::cout << std::max( -1, 3, BinaryFunction ) << '\n';
    std::cout << BinaryFunction( -1, 3 ) << '\n';



}

/* output


3
3
3
1

Process returned 0 (0x0)   execution time : 0.019 s
Press ENTER to continue.



*/
