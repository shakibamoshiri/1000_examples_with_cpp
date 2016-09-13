/// Sequence containers : deque
/// iterator

/// 11_std::deque::end_and_cend
/// definition in header < deque >

/**
iterator end();
const_iterator end() const;
const_iterator cend() const;

Returns an iterator to the element following the last element of the container.
This element acts as a placeholder; attempting to access it results in undefined
behavior.

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
        std::array<const char*,5> wup {"how","are","you","doing","today?"};
        std::array<const char*,1>::iterator it = wup.end();
        /// std::cout<<"Before --it: "<<it<<std::endl; Using form empty iterator is wrong because it is undefined.
        --it;
        std::cout<<"After --it: "<<*it<<std::endl;
    }

}
