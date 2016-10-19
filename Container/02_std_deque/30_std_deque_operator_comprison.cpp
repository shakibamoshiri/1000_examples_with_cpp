/// Sequence containers : deque
/// capacity

/// 30_std::deque::operator_comparison ==, <=, >=, <, >
/// definition in header < deque >

/**
operator==,!=,<,<=,>,=>,>( std::deque);

template< class T, class Alloc >
bool operator==( const deque<T,Alloc>& lhs,
                 const deque<T,Alloc>& rhs );(1)

template< class T, class Alloc >
bool operator!=( const deque<T,Alloc>& lhs,
                 const deque<T,Alloc>& rhs );(2)

template< class T, class Alloc >
bool operator<( const deque<T,Alloc>& lhs,
                const deque<T,Alloc>& rhs );(3)

template< class T, class Alloc >
bool operator<=( const deque<T,Alloc>& lhs,
                 const deque<T,Alloc>& rhs );(4)
template< class T, class Alloc >
bool operator>( const deque<T,Alloc>& lhs,
                const deque<T,Alloc>& rhs );(5)
template< class T, class Alloc >
bool operator>=( const deque<T,Alloc>& lhs,
                 const deque<T,Alloc>& rhs );	(6)


Compares the element of two container.
1,2)    Checks if the contents of 'lhs' and 'rhs' are equal,
        that is ,whether lhs.size() == rhs.size() and each
        element in 'lhs' compares equal with the element in
        'rhs' at the same position.
3-6)    Compares the contents of 'lhs' lexicographically. The
        comparison is preformed by a function equivalent to
        std::lexicographical_compare.

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

        /// comparison you with she
        if (you == she )
            std::cout<<"you equals she"<<std::endl;
        else
            std::cout<<"you does not equal she"<<std::endl;
    }

}
