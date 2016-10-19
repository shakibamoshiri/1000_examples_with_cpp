/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 22_std::list::push_front
/// definition in header < list >

/**
void push_front ( const T& value);
void push_front ( T&& value);

Prepends the given element 'value' to the beginning of the container.
No iterator or reference are invalidated.

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
        out<< camma << l;
        /// for class boy must use &
        /// out<< camma << &l;
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
        std::list<const char*> phone;
        phone.push_back("Samsung");
        phone.push_back("Lg");
        std::string Nexus("Nexus");
        /// this should work but not :(
        //phone.push_back(std::move(Nexus));

        std::cout<<phone<<std::endl;
    }

}
/* out put */
/*


*/
