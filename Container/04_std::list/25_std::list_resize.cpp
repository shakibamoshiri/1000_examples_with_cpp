/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 25_std::list::resize
/// definition in header < list >

/**
void resize ( size_type count,T value=T());
void resize ( size_type count );
void resize ( size_type count, const value_type& value);

Resizes the container to contain 'count' element.
If the the current size is greater than 'count', the container is reduced to its first 'count' elements.
If the current size is less than 'count', additional elements are appended and initialized with copies or 'value'
If the current size is less than 'count'
1)  additional default-inserted element are appended.
2)  additional copies of 'value' are appended.
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
        std::list<int> num{1,2,3,4,5};

        std::cout<<num<<std::endl;

        num.resize(10);

        std::cout<<num<<std::endl;

        num.resize(2);

        std::cout<<num<<std::endl;
    }

}
/* out put */
/*


*/
