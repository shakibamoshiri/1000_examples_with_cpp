/// Sequence containers : deque
/// capacity

/// 27_std::deque::emplace_front
/// definition in header < deque >

/**
template <class... Args>
    void emplace_front (Args&&... args);

Inserts a new element to the beginning of the container. The
element is constructed through std::allocator_traits::construct,
which typically uses placement-new to construct the element in-place
at the location provided by the container. The arguments 'args...'
are forwarded to the constructor as std::forward<Args>(args)....

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
        std::deque<const char*> you {"how","are", "you", "today?" };
        you.emplace_front("say..........");
        std::cout<<you<<std::endl;
    }

}
