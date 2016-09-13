/// Sequence containers : deque
/// capacity

/// 21_std::deque::erase
/// definition in header < deque >

/**
iterator erase ( iterator pos);
iterator erase ( const_iterator pos);
iterator erase ( iterator first, iterator last);
iterator erase ( const_iterator first, const_iterator last);

Removes specified element from the container.

1)  Removes the element at pos.
2)  Removes the element in the range [first, last)

All iterator and reference are invalidate, unless the erased element
are at the end or the beginning of the containers. in which case only
the iterator and reference to the erased element are invalidated.
...
...
...


Return:

**/

#include <iostream>
#include <array>
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
        std::deque<const char*> you {"How","are","you","today?"};
        std::cout<<you<<std::endl;

        /// erase 'How'
        you.erase(you.begin());
        std::cout<<you<<std::endl;

        /// erase 'today?'
        you.erase(you.end());
        std::cout<<you<<std::endl;
    }

}
