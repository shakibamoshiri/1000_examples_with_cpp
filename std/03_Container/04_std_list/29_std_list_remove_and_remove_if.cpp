/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 29_std::list::remove_and_remove_if
/// definition in header < list >

/**
void remove ( const T& value);

template<class UnaryPredicate>
    void remove_if( UnaryPredicate p);

Removes all element satisfying specific criteria. The first version remove all
element that are equal to 'value' the second version remove all elements for
which predicate 'p' returns true.
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
        number.remove(88); /// removing all 88
        std::cout<<number<<std::endl;

        number.remove_if([](int n){return n<0; }); /// remove less that 0

        std::cout<<number<<std::endl;


    }

}
/* out put */
/*


*/
