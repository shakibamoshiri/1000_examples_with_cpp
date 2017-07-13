/*

A review of iterator library


*/

/// front_insert_iterator
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>


int main(){

    const std::list< int > array{ 1,2,3,4,5,6,7,8,9,10 };
    std::list< int > array_2( array.size() );

    std::front_insert_iterator< std::list<int> > bii( array_2 );

    std::copy( array.begin(), array.end(), bii );    // from array to new_array

    for( const int& i : array_2 ){
        printf( "%d\n", i );
    }

}
/* output

10
9
8
7
6
5
4
3
2
1
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

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.


*/
