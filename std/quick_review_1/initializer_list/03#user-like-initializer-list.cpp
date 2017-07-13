/*
    quick review:

    Language Support
        01. type support
        02. dynamic memory management
        03. error handling
        04. initializer-list
        05. variadic function
    **********************************

*/
/// 04. initializer_list



#include <iostream>
#include <initializer_list>

template< typename T >
struct ilist {
    T* ptr;
    std::size_t size = 0;

    template< typename... List >
    ilist( List... list ) :
        size( sizeof... ( list ) )
        { ptr = new T[ size ]; }
    ~ilist(){
        delete [] ptr;
    }
    void print(){
        // initialize
        for( std::size_t index; index < size; ++index ){
            ptr[ index ] = index * index;
        }
        // print
        for( std::size_t index; index < size; ++index ){
            std::cout << ptr[ index ] << ' ';
        }

    }

};




int main(){

    ilist< int > one = { 1,2,3,4,5 };
    one.print();


}
/* output:

0 1 4 9 16

*/
