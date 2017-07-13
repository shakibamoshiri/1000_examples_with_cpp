/*

A review of iterator library


*/

/// back_insert_iterator
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>


int main(){

    const std::vector< int > array{ 1,2,3,4,5,6,7,8,9,10 };
    std::vector< int > array_2( array.size() );

    std::back_insert_iterator< std::vector<int> > bii( array_2 );

    std::copy( array.begin(), array.end(), bii );    // from array to new_array

    for( const int& i : array_2 ){
        printf( "%d\n", i );
    }

}
/* output


0
0
0
0
0
0
0
0
0
0
1
2
3
4
5
6
7
8
9
10

Process returned 0 (0x0)   execution time : 0.019 s
Press ENTER to continue

*/
