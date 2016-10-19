/// Sequence containers : list
/// std::list
///
/// Non-member function
/// 33_std::list::operator ==, !=, <=, <, >=, > ( std::list)
/// definition in header < list >

/**
template< class T, class Alloc >
bool operator==( const list<T,Alloc>& lhs,
                 const list<T,Alloc>& rhs );(1)

template< class T, class Alloc >
bool operator!=( const list<T,Alloc>& lhs,
                 const list<T,Alloc>& rhs );(2)

template< class T, class Alloc >
bool operator<( const list<T,Alloc>& lhs,
                const list<T,Alloc>& rhs );(3)

template< class T, class Alloc >
bool operator<=( const list<T,Alloc>& lhs,
                 const list<T,Alloc>& rhs );(4)

template< class T, class Alloc >
bool operator>( const list<T,Alloc>& lhs,
                const list<T,Alloc>& rhs );(5)

template< class T, class Alloc >
bool operator>=( const list<T,Alloc>& lhs,
                 const list<T,Alloc>& rhs );(6)


Compares the contents of two containers.
1-2) Checks if the contents of lhs and rhs are equal, that is, whether lhs.size() == rhs.size()
    and each element in lhs compares equal with the element in rhs at the same position.
3-6) Compares the contents of lhs and rhs lexicographically. The comparison is performed
    by a function equivalent to std::lexicographical_compare.

Return value
1) true if the contents of the containers are equal, false otherwise
2) true if the contents of the containers are not equal, false otherwise
3) true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
4) true if the contents of the lhs are lexicographically less than or equal the contents of rhs, false otherwise
5) true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
6) true if the contents of the lhs are lexicographically greater than or equal the contents of rhs, false otherwise

**/


#include <iostream>
#include <list>
#include <string>
#include <functional>
//#include <unistd.h>
class Phone {
private:
    const char* name;
    const int age;
protected:
public:
    Phone() : name(""), age(0)
    {}
    Phone(const char* nameTemp,const int ageTemp)
        :name(nameTemp),age(ageTemp) {

        }
    friend std::ostream& operator<<(std::ostream& out,const Phone* objectTemp ){
        std::cout<<objectTemp->name<<' '<<objectTemp->age;
        return out;
    }
};
template < typename L>

std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    out.put('\n');
    char camma = ' ';
    for ( const L l : listTemp ){
        out<< camma << l;
        /// for class boy must use &
         //out<< camma << &l;
        camma=',';
    }
    out.put('\n');
    out.put('}');

    return out;
}
/// only print size of list member:
void getBack(){
    std::cout<<std::endl;
}
template<typename F,typename... L>
void getBack (F first,L... lists){
    std::cout<<first.back()<<' ';
    getBack(lists...);
}


int main(){
    { /// user sample:
    }
    { /// sample of en.reference.com
        std::list<int> n{1,2,3};
        std::list<int> m{1,2,3};
        std::list<int> s{10,20,30};

        if ( n == m ) std::cout<<" n equal to m "<<std::endl;

        if ( s > n ) std::cout<<" s greater than n " <<std::endl;

        if ( m < s ) std::cout<<" m less than s " <<std::endl;



    }

}
/* out put */
/*


*/
