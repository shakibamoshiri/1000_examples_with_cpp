/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 31_std::list::unique
/// definition in header < list >

/**
void unique();

template<class BinaryPredicate>
    void unique(BinaryPredicate p);

Removes all consecutive duplicate elements form the container.
Only first element in each group of equal elements is left.
The first version use operator== to compare the elements, the
second version uses the given binary predicate 'p'.
**/


#include <iostream>
#include <list>
#include <string>
#include <iterator>
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
        std::list<int> number {1,0,33,88,-9, -3, 4,9,7,89,12,-88,88,88};
        std::cout<<number<<std::endl;

        /// unique
        number.unique();
        std::cout<<number<<std::endl;

        /// unique with binary predicate
        /// number.unique([](int p){ return p<0;});
        /// std::cout<<number<<std::endl;

    }

}
/* out put */
/*


*/
