/// Sequence containers : deque
/// capacity

/// 23_std::deque::emplace_back
/// definition in header < deque >

/**
template < class... Args>
    void emplace_back( Args&&... args);

Appends a new element to the end of the container. The element is
constructed through std::allocator_traits::construct, which typically
used placement-new to constructs the element in-place at the location
provided by the container. The argument 'args...' are forwarded to the
constructor as std::forward<Args>(args)....


Return:

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

struct President {
    std::string name;
    std::string country;
    int year;
    President (std::string p_name, std::string p_country,int p_year)
            : name(std::move(p_name)), country( std::move(p_country)), year (p_year)
            {
                std::cout<<"I am being constructed.\n";
            }
    President(President&& other)
            :name(std::move(other.name)), country (std::move(other.country)),year (other.year)
            {
                std::cout<<"I am being moved.\n";
            }
    President& operator=(const President& other) = default;
};

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::deque<President> elections;
        std::cout<<"emplace_back:\n";
        elections.emplace_back("Nelson Mandela","South Africa",1994);

        std::deque<President> reElections;
        std::cout<<"push_back:\n";
        reElections.push_back(President ("Franklin Delano Roosevelt","the USA",1936));

        std::cout<<"\ncontents:\n";
        for ( President const& p :elections ){
            std::cout<<p.name<<" was elected president of "<<p.country<<" in "<<p.year<<std::endl;
        }

        for(President const& p : reElections ){
            std::cout<<p.name<<" Was re-elected president of "<<p.country<<" in "<<p.year<<std::endl;
        }
    }

}
