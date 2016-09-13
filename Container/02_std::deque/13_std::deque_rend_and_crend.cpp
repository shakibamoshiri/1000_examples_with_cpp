/// Sequence containers : deque
/// iterator

/// 13_std::deque::rend_and_rcend
/// definition in header < deque >

/**
reverse_iterator rend();
const_reverse_iterator rend();
const_reverse_iterator crend();

Returns a reverse iterator to the element following the last element
of the reversed container. It corresponds to the element preceding the
first element of the non-reverse iterator container. This element acts
as a placeholder, attempting to access it result in undefined behavior.

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
        std::deque<const char*>::reverse_iterator itRend = what.rend();

        /// I have to -- for itRend because the itRend is empty
        itRend--; /// okay it is correct. point to the first element that is
                  /// : "How"
        /// itRend++ is not correct

        std::cout<<*itRend<<std::endl;/// pirnt : How

        std::cout<<*(--itRend)<<std::endl; /// okay it is correct. First move the iterator, then dereference it
        /// output : the second element, meaning "are"
    }

}
