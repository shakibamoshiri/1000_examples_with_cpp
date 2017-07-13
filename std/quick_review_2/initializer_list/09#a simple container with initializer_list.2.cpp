/*

A review of initializer_list


*/

/// std::initializer_list::size


#include <iostream>
#include <initializer_list>
// #include <fstream>

template< typename T >
struct user_container {

    T* data;
    unsigned length = 0;

    /*********************/

    user_container( std::initializer_list< T > lists ){
        data = new T[ lists.size() ];
        for( T value : lists )
            data[ length++ ] = value;
    }
    user_container( const user_container& ) = delete;
    user_container& operator=( const user_container& ) = delete;

    constexpr T* begin() const { return data; }
    constexpr T* end() const   { return data + length; }
    constexpr unsigned size() const { return length; }

    ~user_container(){
        delete [] data;
    }
};


int main(){

    user_container< char > obj = { 'a', 'b', 'c' };

    for( const char i : obj )
        std::cout << i << ' ';

    std::cout << '\n';

    std::cout << obj.size() << '\n';
    std::cout << *obj.begin() << '\n';
    std::cout << *( obj.end() - 1 ) << '\n';

}
/* output

a b c
3
a
c

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.



*/
