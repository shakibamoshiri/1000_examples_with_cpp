/// Sequence containers : deque
/// capacity

/// 16_std::deque::max_size
/// definition in header < deque >

/**
size_type max_size() const;

Returns the maximum number of element the container is able to hold due
to system or library implementation limitations, i.e. std::distance(
begin(), end() ) for the largest container.


NOTE : This value is typically equal to std::numeric_limit<std::type>>::
max(), and reflects the theoretical limit on the size of the container.
At runtime, the size of the container may be limited to a value smaller
than max_size() by the amount of RAM available.


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
        std::deque<const char*> what {"How", "are", "you", "today ?"};
        std::deque<const char*>::iterator itEnd = what.end();
        std::deque<const char*>::iterator itBegin = what.begin();
        int length_what = ( itEnd - itBegin );
        std::cout<<length_what<<std::endl; /// output : 4

        /// return the max_size of what container
        std::cout<<what.max_size()<<std::endl; /// output : a big number

        std::cout<<( what.end() - what.begin() )<<std::endl; /// : 4
    }

}
