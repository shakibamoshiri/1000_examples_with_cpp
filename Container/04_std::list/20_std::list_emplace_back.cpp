/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 20_std::list::emplace_back
/// definition in header < list >

/**
template<class... Args>
void emplace_back(Args...&& args);

Appends a new element to the end of the container. The element is constructed through
std::allocator_traits::construct, which typically uses placement-new to construct the
element in-place at the location provided by the container. The arguments args... are
forwarded to the constructor as std::froward<Args>(args)... .

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
    }
    { /// sample of en.reference.com
        /// this sample is repeated, like std::vector_emplace_back
        /// you can see that if you want.
        /*

        */
    }

}
/* out put */
/*


*/
