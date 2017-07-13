/*

A review of algorithm library

Other( or miscellaneous )

*/


#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>




/// prev_permutation
//  Transform range to the previous permutation.

// return is: boolean.

template< typename T, unsigned int N >
T* end_of(T ( &array )[ N ] ){
    return array + N;
}


int main(){

    char array[] = "hello";
    char* begin_array = array;
    char* end_array   = end_of( array );

    while( std::prev_permutation( begin_array, end_array ) ){
        for( const char chr : array )
            std::cout << chr;

        std::cout << '\n';
    }

}

/* output

hello
helol
hello
heoll
helol
hello
holle
holel

...
...
...
...

hloel
hlloe
hlleo
hleol
hlelo
heoll
helol
hello
eollh
eolhl
eohll
elolh
elohl
elloh
ellho
elhol
elhlo
eholl
ehlol
ehllo

Process returned 0 (0x0)   execution time : 0.019 s
Press ENTER to continue.


*/
