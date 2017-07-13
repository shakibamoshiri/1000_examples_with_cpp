/*

A review of initializer_list


*/



#include <iostream>
#include <vector>
// #include <fstream>


template< typename... L >
int ( &dotdot( L... list ) )[ sizeof...( L ) ]{
    static int array[] = { list... };
    return array;
}

int main(){

    for( const int i : dotdot( 1,3,5 ) )
        std::cout << i << '\n';


}
/* output

1
3
5

Process returned 0 (0x0)   execution time : 0.017 s
Press ENTER to continue.


*/
