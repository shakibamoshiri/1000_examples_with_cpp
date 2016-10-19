/// Sequence containers : deque
/// capacity

/// 17_std::deque::shrink_to_fit
/// definition in header < deque >

/**
void shrink_to_fit(); since c++11

Returns the removal of unused capacity. It is a non-binding request to reduce
capacity to size(). It depends on the implementation if the request is fulfilled.
All iterator and reference are potentially invalidated. Past-the-end iterator is
also potentially invalidated.

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
        std::deque<int> nums ( 100, 32);
        nums.push_front(1);
        std::cout<<nums<<std::endl;
        nums.pop_front();
        std::cout<<nums<<std::endl;

        nums.clear();
        /// nums now contains no items, but it may still be holding allocated memory.
        /// Calling shrink_to_fit will free any unused memory.

        nums.shrink_to_fit();

        std::cout<<nums<<std::endl;
    }

}
