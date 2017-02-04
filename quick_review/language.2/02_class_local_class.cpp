/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// class
#include <iostream>
#include <algorithm>

int main(){

    int array[] = { 3, 1, 0, -1, 9, 10, 100 };

    struct LocalClass {
        bool operator() ( int first, int second ){ return first > second; }
    };

    std::sort( std::begin( array ), std::end( array ), LocalClass() );

    for( const int temp : array ) std::cout << temp << ' ';
    // 100, 10, 9, 3, 1, 0, -1
}

/* output:



*/
