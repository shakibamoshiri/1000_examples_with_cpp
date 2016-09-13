/// Sequence containers : list
/// std::list
///
/// Capacity
/// 12_std::list::empty
/// definition in header < list >

/**
bool empty() const;
Checks if the container has no elements, i.e whether begin() == end()

**/


#include <iostream>
#include <list>
#include <string>
#include <iomanip>
//#include <unistd.h>
template < typename L>
std::ostream& operator<<(std::ostream& out, const std::list<L>& listTemp){
    out.put('{');
    char camma = '\0';
    for ( const L l : listTemp ){
        out<< camma << l;
        camma=',';
    }
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
        std::list<const char*> you {"How","are","you","today?"};
        std::list<const char*> she;

        bool testYou = you.empty(); /// true if the container is empty, false otherwise
        bool testShe = she.empty(); /// true if the container is empty, false otherwise

        /// testYou == flase
        if (!testYou) std::cout<<"you container is not empty\n";

        /// testShe == true
        if (testShe) std::cout<<"she container is empty\n";

        /// by iterator begin() and end():
        if (!(you.begin() == you.end() ))
            std::cout<<"you is not empty"<<std::endl;
    }

}
/* out put */
/*
*/
