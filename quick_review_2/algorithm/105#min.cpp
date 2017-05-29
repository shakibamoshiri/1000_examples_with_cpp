/*

A review of algorithm library

Min / Max:

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// min
//  return the smallest

// return is: minimum value


bool BinaryFunction( int right, int left ){
    return right < left;
}

int main(){

    std::cout << std::min( -1, 3 ) << '\n';
    std::cout << std::min( { -1, 3 } ) << '\n';
    std::cout << std::min( -1, 3, BinaryFunction ) << '\n';
    std::cout << BinaryFunction( -1, 3 ) << '\n';



}

/* output

-1
-1
-1
1

Process returned 0 (0x0)   execution time : 0.015 s
Press ENTER to continue.




*/
