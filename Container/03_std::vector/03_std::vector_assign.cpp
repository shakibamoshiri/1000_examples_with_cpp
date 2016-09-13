/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;



/// 03_std::vector::assign
/// definition in header < vector >
/**
void assign ( size_type count, const T& value);
template < class InputIt >
void assign (InputIt first, InputIt last);
void assign ( std::initializer_list<T> ilist);

Replaces the contents of the container.

1)  Replaces the contents with 'count' copies of value 'value'
2)  Replaces the contents with copies of those in the range [first, last)
    This overload has the same effect as overload (1) if InputIt is an integral type.
    This overload only participates in overload resolution if InputIt satisfied InputIterator.
3)  Replaces the contents with the element from the initializer list 'ilist'

Return:

**/

#include <iostream>
#include <string>
#include <vector>

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
        std::vector<const char*> you;
        you.assign(5,"you");
        std::cout<<you<<std::endl;/// you you you you you

        std::vector<const char*> she;
        she.assign(you.begin(),you.begin()+1); /// takes only first element
        std::cout<<she<<std::endl; /// you

        std::initializer_list<const char*> ilist{"How are you today?"};

        std::vector<const char*> he;
        /// or we can:
        /// std::vector<const char*> he = ilist;
        /// std::vector<const char*> he {ilist};

        he.assign(ilist);

        std::cout<<he<<std::endl; /// how are you today?


    }

}
