/// Sequence containers : deque
/// capacity

/// 26_std::deque::pop_front
/// definition in header < deque >

/**
void pop_front();

Removes the first element of the container.

Iterator and reference to the erased element are invalidated. It is
unspecified whether the past-the-end iterator is invalidated if the
element is the last element is the container. Other reference and
iterators are not affected. Iterator and reference to the erased
element are invalidated. If the element is the last element in the
container, the past-the-end iterator is also invalidated. Other
reference and iterators are not affected.

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
        you.pop_front();
        std::cout<<you<<std::endl;
    }

}
