/// Sequence containers : deque
/// capacity

/// 18_std::deque::clear
/// definition in header < deque >

/**
void clear();

Removes all element form the container.
Invalidates any reference, pointer, or iterator referring to
contained element. May invalidate any past-the-end iterators.

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
        std::deque<int> nums ( 10, 10);
        nums.push_front(99);
        std::cout<<nums<<std::endl;
        nums.pop_front();
        /// before clearing
        std::cout<<nums<<std::endl;

        nums.clear();
        /// nums now contains no items, but it may still be holding allocated memory.
        /// Calling shrink_to_fit will free any unused memory.

        /// After clearing
        std::cout<<nums<<std::endl;
    }

}
