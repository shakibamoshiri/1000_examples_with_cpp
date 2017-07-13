/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 17_std::list::emplace
/// definition in header < list >

/**
template<class... Args>
    iterator emplace(const_iterator pos, Args&&... args);

Inserts a new element into the container directly before 'pos'.
The element is constructed through std::allocator_traits::construct,
which typically uses placement-new to construct the element in-place
at a location provided by the container. The arguments 'args...' are
forwarded to the constructor as std::forward<Args>(args)... .

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
template<typename I,typename T>
std::iterator<I,T> operator+(std::iterator<I,T>& it,const int i){
}
int main(){
    { /// user sample:

    }
    { /// sample of en.reference.com
        std::list<const char*> you;

        const char* temp[4] = {"how","are","you","today?"};

        for ( const char* t :temp)
            std::cout<<t<<std::endl;

        std::cout<<"\n...........................\n";
        for ( const char* t : temp)
            you.emplace(you.begin()++,t); /// I think this a bad design in c++
            /// you.begin() here, is , like you.begin() without using ++

        std::cout<<you<<std::endl;
    }

}
/* out put */
/*


*/
