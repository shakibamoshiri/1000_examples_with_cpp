/// Sequence containers : deque
/// capacity

/// 15_std::deque::size
/// definition in header < deque >

/**
size_type size() const();

Returns the number of element in the container, i.e
    std::distance ( being(), end() );

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

        std::cout<<what.size()<<std::endl; /// output : 4

        std::cout<<( what.end() - what.begin() )<<std::endl; /// : 4
    }

}
