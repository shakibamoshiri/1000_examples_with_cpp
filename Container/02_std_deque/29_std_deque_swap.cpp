/// Sequence containers : deque
/// capacity

/// 29_std::deque::swap
/// definition in header < deque >

/**
void swap ( deque& other);

Exchange the contests of the container with those of 'other'.
Does not invoke any move,copy,or swap operation on individual
element. All iterator and reference remain valid. The part-the-end
iterator is invalidated.
If  std::allocator_traits<allocator_type>::propagte_on_container_swap::value
is true, then the allocators are exchange using an unqualified call to
non-member 'swap'. Otherwise, they are not swapped ( and if get_allocator()!=
other.get_allocator(), the behavior is undefined. ).

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

        you.swap(she);

        std::cout<<you<<std::endl;
        std::cout<<she<<std::endl;
    }

}
