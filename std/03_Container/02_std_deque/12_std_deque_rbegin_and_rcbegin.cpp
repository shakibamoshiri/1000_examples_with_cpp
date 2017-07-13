/// Sequence containers : deque
/// iterator

/// 12_std::deque::rbegin_and_crbegin
/// definition in header < deque >

/**
reverse_iterator rbeging();
const_reverse_iterator rbegin();
const_reverse_iterator crbegin();

Returns a reverse iterator to the first element of the reversed container.
It corresponds to the last element of the non-reversed container.

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
        std::deque<const char*>::reverse_iterator it_rbegin = what.rbegin();
        std::deque<const char*>::iterator it_begin = what.begin();
        std::cout<<*it_rbegin<<std::endl; /// output : today? = reverse begin
        /// it_begin or it_rbeing = "something" is wrong
        std::cout<<what<<std::endl;
    }

}
