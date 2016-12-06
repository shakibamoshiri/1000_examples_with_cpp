/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 24_std::vector::push_back
/// definition in header < vector >
/**
void push_back(const T& value);
void push_back(T&& value);

Appends the given element 'value' to the end of the container.
1)  The new element is initialized as a copy of a 'value'
2)  'value' is moved into the new element.
If the new size() is greater then capacity() then all iterator
and reference ( including the past-the-end iterator ) are invalidated.
Otherwise only the past-the-end iterator is invalidated.

**/


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

//#include <unistd.h>
template<typename V>
std::ostream& operator<<(std::ostream& out,const std::vector<V>& v){
    out.put('(');
    char comma = '\0';
    for ( const auto& ve : v){
        out << comma << ve;
        comma = ',';
    }
    return out << ')';
}

template < typename V>
using vec = std::vector<V>;


int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::vector<std::string> you;
        you.push_back("how");
        you.push_back("are");
        you.push_back("you");
        std::cout<<you<<std::endl;

        std::string today("today?");
        you.push_back(std::move(today));

        std::cout<<"vector holds: ";
        std::cout<<you<<std::endl;

        std::cout<<"Moved form string holds: "<<std::quoted(today)<<std::endl; /// ""

    }

}
