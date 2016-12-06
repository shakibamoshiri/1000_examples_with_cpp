/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 26_std::vector::pop_back
/// definition in header < vector >
/**
Removed the last element of the container.
Calling 'pop_back()' on an empty container is undefined.
No iterators or references except for back() and end() are invalidated.

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
        out<<temp.name<<' '<<temp.country<<' '<<temp.year<<'\n';
        return out;
    }
    friend std::ostream& operator<<(std::ostream& out,const President& temp){
        out<<temp.name<<' '<<temp.country<<' '<<temp.year<<'\n';
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
        std::vector<President> elections;

        elections.emplace_back("A","B",1);
        elections.emplace_back("A_A","B_B",11);
        elections.emplace_back("A_A_A","B_B_B",111);

        std::cout<<elections<<std::endl;

        elections.pop_back();

        std::cout<<elections<<std::endl; /// popped A_A_A B_B_B 111 form container





    }

}
