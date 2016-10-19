/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Non-member function.



/// 28_std::vector::operator==,<,>,<=,>=,!= (std::vector)
/// definition in header < vector >
/**
template< class T, class Alloc >
bool operator==( const vector<T,Alloc>& lhs,
                 const vector<T,Alloc>& rhs );(1)
template< class T, class Alloc >
bool operator!=( const vector<T,Alloc>& lhs,
                 const vector<T,Alloc>& rhs );(2)
template< class T, class Alloc >
bool operator<( const vector<T,Alloc>& lhs,
                const vector<T,Alloc>& rhs );(3)
template< class T, class Alloc >
bool operator<=( const vector<T,Alloc>& lhs,
                 const vector<T,Alloc>& rhs );(4)
template< class T, class Alloc >
bool operator>( const vector<T,Alloc>& lhs,
                const vector<T,Alloc>& rhs );(5)
template< class T, class Alloc >
bool operator>=( const vector<T,Alloc>& lhs,
                 const vector<T,Alloc>& rhs );(6)

Compares the contents of two container.
1-2)    Checks if the contents of 'lhs' and 'rhs' are equal, that is,
        whether lsh.size() == rhs.size() and each element in 'lhs' com
        pares equal  with the element in 'rhs' at the same position.
3-6)    Compares the contents of 'lhs' and 'rhs' lexicographically. The
        comparison is performed by function equivalent to std::lexicographical_compare.

1)  true if the contents of the containers are equal, false otherwise
2)  true if the contents of the containers are not equal, false otherwise
3)  true if the contents of the lhs are lexicographically less than the
    contents of rhs, false otherwise
4)  true if the contents of the lhs are lexicographically less than or
    equal the contents of rhs, false otherwise
5)  true if the contents of the lhs are lexicographically greater than
    the contents of rhs, false otherwise
6)  true if the contents of the lhs are lexicographically greater than
    or equal the contents of rhs, false otherwise
**/


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

//#include <unistd.h>
struct President {
    std::string name;
    std::string country;
    int year;

    President (std::string nameTemp,std::string countryTemp, int yearTemp)
            : name (std::move(nameTemp)), country(std::move(countryTemp)), year ( yearTemp){
                std::cout<<"I am being constructed.\n";
            }
    President(President&& other)
            : name (std::move(other.name)), country(std::move(other.country)), year(other.year){
                std::cout<<"I am being moved.\n";
    }
    President& operator=(const President& other) = default;
    friend std::ostream& operator<<(std::ostream& out,President& temp){
        out<<temp.name<<' '<<temp.country<<' '<<temp.year;
        return out;
    }
    friend std::ostream& operator<<(std::ostream& out,const President& temp){
        out<<temp.name<<' '<<temp.country<<' '<<temp.year;
        return out;
    }

};

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


std::ostream& operator<<(std::ostream& out,const std::vector<President>& v){

    for ( President const& p : v)
        out<<p<<'\n';

return out;
}


template < typename V>
using vec = std::vector<V>;



int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::vector<std::string> she {"she is a nurse"};
        std::vector<std::string> he {"he is a teacher"};
        std::vector<std::string> I{"he is a teacher"};

        std::boolalpha(std::cout);

        std::cout<<"I == she:    "<< (I==she)<<std::endl;
        std::cout<<"he == I:     "<< (he==I)<<std::endl;
        std::cout<<"he != she:   "<< (he!=she)<<std::endl;


    }

}
