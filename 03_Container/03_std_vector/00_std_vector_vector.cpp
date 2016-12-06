/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;



/// 00_vector::vector
/// definition in header < vector >

/**
explicit vector( const Allocator& alloc = Allocator() );        (until C++14)
vector() : vector( Allocator() ) {}
explicit vector( const Allocator& alloc );(since C++14)(2)
explicit vector( size_type count,
                 const T& value = T(),
                 const Allocator& alloc = Allocator());          (until C++11)
         vector( size_type count,
                 const T& value,
                 const Allocator& alloc = Allocator());       (since C++11)(3)
explicit vector( size_type count );                             (since C++11)(until C++14)
explicit vector( size_type count, const Allocator& alloc = Allocator() );       (since C++14)
template< class InputIt >
vector( InputIt first, InputIt last,
        const Allocator& alloc = Allocator() );                   (4)
vector( const vector& other );                                 (5)
vector( const vector& other, const Allocator& alloc );         (5) 	(since C++11)
vector( vector&& other )(6) 	(since C++11)
vector( vector&& other, const Allocator& alloc );                (6) 	(since C++11)
vector( std::initializer_list<T> init,
        const Allocator& alloc = Allocator() );                  (7) 	(since C++11)



Constructs a new container form a variety of data sources, optionally using
a user supplied allocator 'alloc'.

1)  Default constructor. Constructs an empty container.
2)  Constructs the container with 'count' copies of element with value 'value'
3)  constructs the container with 'count' default-inserted instances of T. No copies are made.
4)  constructs the container with the contents of range [first, last). This
    constructor has the same effect as overload (2) if 'InputIt' is an integral type.
    This overload only participates in overload resolution if 'InputIt' satisfies
    'InputIterator', to avoid ambiguity with the overload (2).
5)  Copy constructor. construct the container with the copy of the contents
    of 'other'. If 'alloc' is not provided, allocator is obtained by calling
    std::allocator_traits<allocator_type>::select_on_container_copy_construction( other.get_allocator().
6)  Move constructor. construct the container with the contents of 'other'
    using move semantics. If 'alloc' is not provided, allocator is obtained
    by move-constructor from the allocator belonging to 'other'.
7)  Constructs the container with the contents of the initializer list 'ilist'.

Return:

**/

#include <iostream>
#include <string>
#include <vector>

//#include <unistd.h>
template<typename V>
std::ostream& operator<<(std::ostream& out,const std::vector<V>& v){
    out.put('(');
    char comma = '\0';
    for ( const auto& ve : v){
        out << comma << ve;
        comma = ',';
    }
    return out << ')';
}

template < typename V>
using vec = std::vector<V>;



int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        /// c++11 initializer list syntax:
        std::vector<std::string> word1 {"the","froguar","is","also","cursed"};
        std::cout<<"word1 : "<<word1<<std::endl;

        /// word1  == word2:
        std::vector<std::string> word2(word1.begin(),word1.end());
        std::cout<<"word2: "<<word2<<std::endl;

        /// word3 == word1:
        std::vector<std::string> word3(word1);
        std::cout<<"word3: "<<word3<<std::endl;

        /// word4 by copies of the same string
        std::vector<std::string> word4(4,"vector");
        std::cout<<"word4: "<<word4<<std::endl;
    }

}
