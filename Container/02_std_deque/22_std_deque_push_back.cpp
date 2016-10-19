/// Sequence containers : deque
/// capacity

/// 22_std::deque::bush_back
/// definition in header < deque >

/**
void push_back ( const T& value);
void push_back ( T&& value);

Appends the given element 'value' to the end of the container.
1)  The new element is initialized as a copy of 'value'.
2)  'value' is moved into the new element. ( using : std::move )


Return:

**/

#include <iostream>
#include <string>
#include <iomanip>
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
        std::deque<std::string> numbers;

        numbers.push_back("ABC");

        std::string s = "DEF";

        std::cout<<numbers<<std::endl;

        numbers.push_back(std::move(s));

        std::cout<<"deque holds: ";
        for ( auto&& i : numbers )
            std::cout<<std::quoted(i)<<' ';

        std::cout<<"\nMoved-from string holds "<<std::quoted(s)<<std::endl;


    }

}
