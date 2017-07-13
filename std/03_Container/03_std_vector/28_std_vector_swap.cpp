/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 28_std::vector::swap
/// definition in header < vector >
/**
void swap( vector& other);
Exchanges the contents of the container with those of 'other'.
Does not invoke any more, copy or swap operation on individual
element. All iterators and reference remain valid. The past-the-end
iterator is invalidated.
If std::allocator_traits<allocator_type>::propagate_on_container_swap::value
is true, then the allocators are exchanged using an unqualified all to non-
member 'swap'. Otherwise, they are not swapped ( and if get_allocator() != other
get_allocator(), the behavior is undefined ).

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

        std::cout<<"Before swapping | she: "<<she<<std::endl;
        std::cout<<"Before swapping | he : "<<he<<std::endl;

        she.swap(he);

        std::cout<<"After swapping | she: "<<she<<std::endl;
        std::cout<<"After swapping | he : "<<he<<std::endl;


    }

}
