/// Sequence containers : deque
/// capacity

/// 14_std::deque::empty
/// definition in header < deque >

/**
bool empty () const;

Checks if the container has no element, i.e whether begin() == end()

Return:
true if the container is empty, otherwise false
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
        bool testEmpty = ( itEnd == itBegin );
        if(testEmpty) /// false = is not empty
            std::cout<<"what container is empty"<<std::endl;
        else
            std::cout<<"what container is not empty"<<std::endl;

        std::deque<char> ch;
        if(ch.empty()) /// return true that meaning it is empty
            std::cout<<"yes the container is empty"<<std::endl;

        /// in fact empty() means : is the container empty ? or is_empty()
        /// true => yes it is empty
        /// false => no it is not empty
    }

}
