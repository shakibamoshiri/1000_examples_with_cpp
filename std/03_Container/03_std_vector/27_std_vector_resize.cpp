/// Sequence containers : vector
/// std::vector is a sequence container that encapsulates dynamic size array.
/// template < class T, class Allocator = std::allocator<T> > class vector;
/// Section : Modifiers



/// 27_std::vector::resize
/// definition in header < vector >
/**
void resize ( size_type count,T value = T() );
void resize ( size_type count );
void resize ( size_type count, const value_type& value );

Resizes the container to contain 'count' element.
If the current size is greater than 'count', the container is reduced to its
first 'count'. If the current size is lass than 'count', additional elements
are appended and initialized with copies of 'value'. If the current size is
lass than 'count'
1)  Additional default-inserted element are appended.
2)  Additional copies of 'value' are appended.

Note:
If value-initialization in overload(1) i undesirable, for example, if the
elements are of non-class type and zeroing out is not needed, it can be
avoided by providing a custom Allocator::construct.

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
        std::vector<int> integer = {1,2,3,4,5,6,7,8};

        std::cout<<"the vector holds: \n";
        std::cout<<integer<<std::endl;

        integer.resize(20);

        std::cout<<"after resizing up 20: \n";
        std::cout<<integer<<std::endl;

        integer.resize(3);

        std::cout<<"After resizing down 3: \n";
        std::cout<<integer<<std::endl;
    }

}
/*
output:

the vector holds:
(1,2,3,4,5,6,7,8)
after resizing up 20:
(1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0,0,0,0)
After resizing down 3:
(1,2,3)

Process returned 0 (0x0)   execution time : 0.019 s
Press ENTER to continue.


*/
