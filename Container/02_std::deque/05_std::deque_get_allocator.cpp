/// Sequence containers : deque

/// 05_std::deque::get_allocator
/// definition in header < deque >

/**
allocator_type get_allocator() const;

Returns the allocator associated with the container.

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
template < typename D>
using ded = std::deque<D>;

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        ded<int> i {0,1,2,3,4};
        i.get_allocator();/// how does it work ?
    }

}
