/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 24_std::list::pop_front
/// definition in header < list >

/**
void pop_front();

Removes the first element of the container.
References and iterators to the erased element are invalidated.

**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
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
        //out<< camma << l;
        /// for class boy must use &
         out<< camma << &l;
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
        std::list<Phone> cell;
        cell.emplace_front("Iran +",98);
        cell.emplace_front("American +",1);

        std::cout<<cell<<std::endl;

        cell.pop_front();

        std::cout<<cell<<std::endl;
    }
    { /// sample of en.reference.com
        /// no sample
    }

}
/* out put */
/*


*/
