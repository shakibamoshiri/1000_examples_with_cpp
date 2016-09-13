/// Sequence containers : deque
/// capacity

/// 24_std::deque::pop_back
/// definition in header < deque >

/**
void pop_back();

Removes the last element of the container.
Calling pop_back on an empty container is undefined. <------
Iterators and reference to the erased element are invalidated.
It is unspecified whether the past-the-end iterator is invalidated.
Other reference and iterator are not affected.
Iterator and reference to the erased element are invalidated. The
past-the-end iterator is also invalidated. Other reference and iterators
are not affected.

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
        std::deque<const char*> you {"how", "are", "you", "today?" };
        std::cout<<you<<std::endl;

        /// remove "today?" from the container you. The last element
        you.pop_back();

        std::cout<<you<<std::endl;
    }

}
