/*

A review of initializer_list


*/



#include <iostream>
// #include <iterator>
// #include <fstream>


struct S {
    S( int one, int two ){
        std::cout << "the first constructor was called\n";
    }
    S( std::initializer_list< int > init_list ){
        std::cout << "the second constructor was called\n";
    }
};

int main(){

    S one( 1, 3 );      // calls the S( int, int )
    S two{ 1, 3 };      // calls the S( initializer_list< int > )

}
/* output

the first constructor was called
the second constructor was called

Process returned 0 (0x0)   execution time : 0.029 s
Press ENTER to continue.



*/
