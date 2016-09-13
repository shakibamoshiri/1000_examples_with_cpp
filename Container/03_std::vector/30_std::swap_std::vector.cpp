/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Non-member function.



/// 28_std::swap(std::vector);
/// definition in header < vector >
/**
template<class T,class Alloc>
void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs);

Specializes the std::swap algorithm for std::vector.
Swaps the contents of 'lhs' and 'rhs'.Calls lhs.swap(rhs).

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

        /// running: lhs.swap(rhs)
        std::swap(she,he);

        std::cout<<"she:   "<<she<<std::endl;
        std::cout<<"he :   "<<he<<std::endl;

        /*

        output:

        she:   (he is a teacher)
        he :   (she is a nurse)

        */


    }

}
