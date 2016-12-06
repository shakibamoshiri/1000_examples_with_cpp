/// Sequence containers : deque

/// 08_std::deque::front
/// definition in header < deque >

/**
reference front();
const_reference front() const;

Returns a reference to the first element in the container.
Calling front on en empty container is undefined.

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
        std::cout<<i.front()<<std::endl;
        i.front() = "TEST";
        std::cout<<i.front()<<std::endl;
        std::cout<<i<<std::endl;
        const char* t[4] = {i.at(0), i.at(1), i.at(2), i.at(3)};

        for ( const char* p : t )
            std::cout<<p<<' ';



    }

}
