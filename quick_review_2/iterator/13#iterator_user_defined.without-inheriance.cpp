/*

A review of iterator library


*/

/// class iterator
//


#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>


class user_iterator {
private:
    int* ptr;

public:
    user_iterator( int* temp ):
        ptr( temp )
        {}
    user_iterator( const user_iterator& other ):
        ptr( other.ptr )
        {}

    user_iterator& operator++(){
        ++ptr;
        return *this;
    }
    user_iterator operator++( int ){
        user_iterator temp( *this );
        operator++();
        return temp;
    }
    bool operator==( const user_iterator& right_hand_side ){
        return ptr == right_hand_side.ptr;
    }
    bool operator!=( const user_iterator& right_hand_side ){
        return ptr != right_hand_side.ptr;
    }
    int& operator*(){
        return *ptr;
    }
};


int main(){

    int number[] { 1,2,3,4,5,6,7,8,9,10 };

    user_iterator from( number );
    user_iterator upto( number + 7 );

    for( user_iterator it = from; it != upto; ++it ){
        std::cout << *it << '\n';
    }

}
/* output

1
2
3
4
5
6
7

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



*/
