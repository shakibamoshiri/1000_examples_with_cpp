/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 21_std::list::pop_back
/// definition in header < list >

/**
void pop_back();

REmoves the last element of the container.
Calling 'pop_back' on an empty container is undefined.
References and iterators to the erased element are invalidated.

**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
//#include <unistd.h>
class Boy {
private:
    const char* name;
    const int age;
protected:
public:
    Boy() : name(""), age(0)
    {}
    Boy(const char* nameTemp,const int ageTemp)
        :name(nameTemp),age(ageTemp) {

        }
    friend std::ostream& operator<<(std::ostream& out,const Boy* objectTemp ){
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
        Boy one("Shakib",29);
        std::cout<<&one<<std::endl;

        std::list<Boy> family;
        family.emplace_back("I am Shakib",29);
        family.emplace_back("I am Omid",29);
        family.emplace_back("I am Farshid",28);
        family.emplace_back("I am Saber",25);

        std::cout<<family<<std::endl;

        /// removing : "I am Saber",25
        family.pop_back();

        std::cout<<family<<std::endl;
    }
    { /// sample of en.reference.com
    }

}
/* out put */
/*


*/
