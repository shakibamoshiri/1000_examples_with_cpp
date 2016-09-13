/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 26_std::list::swap
/// definition in header < list >

/**
void swap ( list& other );
Exchanges the contains of the container with those of 'other'
Does not invoke any move, copy, or swap operation on invalidated
element.

invoke:
invoke something ( computing ) to begin to run a program, etc.
This command will invoke the HELP system.

All iterators and reference remind valid. It is unspecified whether an iterator
holding the past-the-end value in this container will refer to the this or the
other container after the operation.





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
        std::list<std::string> he {"He is a teacher"};
        std::list<std::string> she { "He is a nurse"};
        std::cout<<"he : "<<he<<std::endl;
        std::cout<<"She: "<<she<<std::endl;
        std::cout<<"...swapping..."<<std::endl;
        he.swap(she);
        std::cout<<"he : "<<he<<std::endl;
        std::cout<<"he : "<<she<<std::endl;
    }

}
/* out put */
/*


*/
