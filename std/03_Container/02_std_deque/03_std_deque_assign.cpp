/// Sequence containers : deque

/// 03_std::deque::assign
/// definition in header < deque >

/**
void assign ( size_type count, const T& value );
template < class InputIt >
    void assign ( InputIt first, InputIt last );
void assign ( std::initializer_list < T > ilist);

Replaces the contents of the containers.
1)  Replaces the contents with count copies of value 'value'
2)  Replaces the contents with copies of those in the range
    [ first, last ). This overload has the same effect as
    overload resolution if InputIt satisfies InputIterator.
3)  Replaces the contents with the element from the initialize_list 'ilist'


**/

#include <iostream>
#include <string>
#include <deque>

//#include <unistd.h>

template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, std::deque<ALL_TYPE>& de){
    out.put('[');

    char ch = '\0';
    for ( const auto& t : de ){
        out<<ch<<t;
        ch = ',';
    }
    out.put(']');
    return out;
}
template < typename D>
using ded = std::deque<D>;

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        ded<char> character;
        character.assign(20,'.');
        std::cout<<character<<std::endl;

        ded<char> tmp;
        tmp.assign(character.begin(),character.end());
        std::cout<<tmp<<std::endl;

        tmp.assign({'a','s','s','g','i','n' });
        std::cout<<tmp<<std::endl;
    }

}
