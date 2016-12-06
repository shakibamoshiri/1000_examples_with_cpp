/// Sequence containers : deque
/// capacity

/// 20_std::deque::emplace
/// definition in header < deque >

/**
template < class... Args>
iterator emplace ( const_iterator pos, Args&&... args);

Inserts a new element into the container directly before 'pos'.
The element is constructed through std::allocator_traits::construct.
which typically uses placement-new to constructs the element in-place
at a location provided by the container. The arguments args... are
forwarded to the constructor as std::forward<Args>(args)....

All iterator, including the past-the-end iterator, are invalidated.
Reference are invalidated too, unless pos == being() or pos == end(),
in which case they are not invalidated.

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

        you.emplace(you.begin(),"I am"); /// insert 'I am'  before 'How'

        std::cout<<you<<std::endl;

        you.emplace(you.end(),"hello"); /// insert 'hello' after 'today?'
        std::cout<<you<<std::endl;
    }

}
