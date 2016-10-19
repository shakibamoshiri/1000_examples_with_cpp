/// Sequence containers : list
/// std::list
///
/// Non-member function
/// 34_std::swap( std::list)
/// definition in header < list >

/**
template<class T,class Alloc>
void swap ( list<T,Alloc>& lhs, list<T,Alloc>&rhs);

Specializes the std::swap algorithm for std::list.
Swaps the contents of 'lhs' and 'rhs' calls lhs.swap(rhs).
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
        std::list<int> m{1,2,3};
        std::list<int> s{10,20,30};

        std::swap(m,s);

        std::cout<<m<<std::endl;
        std::cout<<s<< std::endl;
    }

}
/* out put */
/*


*/
