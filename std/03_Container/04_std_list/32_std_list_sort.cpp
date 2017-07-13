/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 32_std::list::sort
/// definition in header < list >

/**
void sort();

template<class Compare>
    void sort ( Compare comp);

Sorts the elements in ascending order. The order of equal elements is preserved.
The first version uses operator < to compare the element, the second version uses
the given comparison 'comp'

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
        std::list<int> number {0,3,8,9,1,2,6,5,7,4};

        std::cout<<number<<std::endl;

        number.sort();

        std::cout<<number<<std::endl;

        number.sort(std::greater<int>());

        std::cout<<number<<std::endl;


    }

}
/* out put */
/*


*/
