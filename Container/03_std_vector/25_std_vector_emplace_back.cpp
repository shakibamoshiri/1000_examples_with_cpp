/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 25_std::vector::emplace_back
/// definition in header < vector >
/**
template<class... Arges>
void emplace_back( Args&&... args);

Appends a new element to the end of the container. The element is
constructed though std::allocator_traits_construct, which typically
uses placement-new to construct the element in-place at the location
provided by the container. The arguments 'args...' are forwarded to the
container as std::forward<Args>(args)....
If the 'size()' is greater then capacity() then all iterators and references
( including the past-the-end iterator) are invalidated. Otherwise only the
past-the-end iterator is invalidated.

Note:
The specialization std::vector<bool> did not have emplace_back()
member until c++14

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
        out<<temp.name<<' '<<temp.country<<' '<<temp.year<<'\n';
        return out;
    }
};

int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::vector<President> elections;
        std::cout<<"emplace_back: \n";
        elections.emplace_back("Nelson Mandela","South Africa",1994);

        std::vector<President> reElections;
        std::cout<<"\npush_back: \n";
        reElections.push_back(President("Franklin Delano Roosevelt","the USA",1936));

        /// testing << for President
        President p("A","B",1);
        std::cout<<p<<std::endl;

        /// how to print
        for (President const& ee : elections)
            std::cout<<ee.name<<' '<<ee.country<<' '<<ee.year<<std::endl;

        /// another way to print
        std::cout<<std::endl;
        President& ite = *elections.begin();
        President& itre = *reElections.begin();

        std::cout<<ite;
        std::cout<<itre<<std::endl;
    }

}
