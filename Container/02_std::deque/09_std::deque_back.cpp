/// Sequence containers : deque

/// 09_std::deque::back
/// definition in header < deque >

/**
reference back();
const_reference back() const;

Returns reference to the last element in the container.
Calling 'back' on an empty container is undefined.

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
        ded<const char*> i {"test","at","in","std::deque"};
        std::cout<<i<<std::endl;
        std::cout<<i.back()<<std::endl;
        i.back() = "+++++++";
        std::cout<<i<<std::endl;

    }

}
