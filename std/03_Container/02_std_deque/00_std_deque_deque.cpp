/// Sequence containers : deque

/// 00_std::deque::deque
/// definition in header < deque >

/**
explicit deque( const Allocator& alloc = Allocator() );(until C++14)
deque() : deque( Allocator() ) {}
explicit deque( const Allocator& alloc );(since C++14)(2)
explicit deque( size_type count,
                const T& value = T(),
                const Allocator& alloc = Allocator());(until C++11)
deque( size_type count,
                const T& value,
                const Allocator& alloc = Allocator());(since C++11)(3)
explicit deque( size_type count ); (since C++11) (until C++14)
explicit deque( size_type count, const Allocator& alloc = Allocator() ); (since C++14)
template< class InputIt >
deque( InputIt first, InputIt last,
       const Allocator& alloc = Allocator() ); (4)
deque( const deque& other ); (5)
deque( const deque& other, const Allocator& alloc ); (5) 	(since C++11)
deque( deque&& other ) (6) 	(since C++11)
deque( deque&& other, const Allocator& alloc ); (6) 	(since C++11)
deque( std::initializer_list<T> init,
       const Allocator& alloc = Allocator() ); (7) 	(since C++11)

Constructs a new container form a variety of date sources, optionally
using a user supplied allocator 'alloc'.
1   Default constructor. Constructs an empty container.
2   Constructs the container with 'count' copies of element with value 'value'
3   Constructs the container with 'const' default-inserted instances of T. No copies are made.
4   Constructs the container with the constants of the range [ first, last )
    This constructor has the same effect as overload resolution if 'InputIt'
    satisfies 'InputIterator', to avoid ambiguity with the overload(2)
5   Copy constructor. constructs the container with the copy of the contents
    of 'other'. If 'alloc' is not provided, allocator is obtained by calling
    std::allocator_traits<allocator_type>::select_on_container_copy_construction(
    other.get_allocator()).
6   Move constructor. construct the container with the contents of 'other'
    using move semantics. If 'alloc' is not provided, allocator is obtained
    by move-constructor form the allocator belonging to 'other'.
7   constructs the container with the contents of the initializer list init.
**/

#include <iostream>
#include <string>
#include <deque>

#include <unistd.h>
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
template< typename TT>
std::ostream& operator<<(std::ostream& out,std::deque<TT>&& de){
    /// for test but not any more to continue
    return out;
}
int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::deque<char> ch {'a','b','c','d','e'};
        std::cout<<ch<<std::endl;
        ch = {'d','d','d','d','d'};
        std::cout<<ch<<std::endl; // [d,d,d,d,d]

        std::deque<const char*> family {"father", "mother", "sister", "brother"};
        std::cout<<family<<std::endl;

        std::deque<const char*> family_temp (family.begin(),family.end());
        std::cout<<family_temp<<std::endl;

        std::deque<char> ch_2 (10,'=');
        std::cout<<ch_2<<std::endl;

        std::deque<const char*>::iterator it = family.end();
        it--;
        std::deque<const char*> ch_3 (10, *it);
        std::cout<<ch_3<<std::endl;

        std::deque<char> ch_4 (std::deque<char>(5,'|'));
        std::cout<<ch_4<<std::endl;

        std::initializer_list<char> i = {'a','b','c'};
        std::deque<char> ch_5(i);
        std::cout<<ch_5<<std::endl;

        std::cout<<std::deque<char>('1')<<std::endl;
    }

}
