/// Sequence containers : deque
/// capacity

/// 25_std::deque::push_front
/// definition in header < deque >

/**
void push_front( const T& value);
void push_front ( const T&& value); since c++11

Prepends the given element 'value' to the beginning of the container.
All iterator, including the past-the-end iterator, are invalidated.
No reference are invalidated

Return:

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
template<typename ALL_TYPE>
std::ostream& operator<<(std::ostream& out, const std::deque<ALL_TYPE>& de){
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
        std::deque<const char*> you {"are", "you", "today?" };
        std::cout<<you<<std::endl;

        /// send "how" to the first element in container you
        you.push_front("How");
        /// or we can use this method:
        /*
        you.push_front("how")
        */

        std::cout<<you<<std::endl;

    }

}
