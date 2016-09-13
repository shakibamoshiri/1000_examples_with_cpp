/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 19_std::list::push_back
/// definition in header < list >

/**
void push_back(const T& value);
void push_back(T&& value);

Appends the given element 'value' to the end of container.
1)  The new element is initialized as copy of 'value'
2)  'value' is moved into the new element.

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
        std::list<std::string> numbers;
        numbers.push_back("abc");

        std::string s("def");
        numbers.push_back(std::move(s));

        std::cout<<"numbers holds: "<<numbers<<std::endl;
        std::cout<<std::quoted(s)<<std::endl;
    }

}
/* out put */
/*


*/
