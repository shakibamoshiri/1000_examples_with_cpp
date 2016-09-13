/// Sequence containers : deque
/// capacity

/// 31_std::swap ( std::deque)
/// definition in header < deque >

/**

template< class T, class Alloc >
void swap( deque<T,Alloc>& lhs, deque<T,Alloc>& rhs );

Specializes the std::swap algorithm for std::deque. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).


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
        std::deque<const char*> she {"she","is","a","nurse"};

        /// swapping two container with std::swap
        std::swap(you,she);

        std::cout<<you<<std::endl;
    }

}
