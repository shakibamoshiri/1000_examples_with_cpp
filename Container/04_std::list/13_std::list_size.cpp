/// Sequence containers : list
/// std::list
///
/// Capacity
/// 13_std::list::size
/// definition in header < list >

/**

size_type size() const;

Returns the number of element in the container, i.e std::distance(being(), end() )
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

        std::cout<<"the size of you is : "<<you.size()<<std::endl;
        std::cout<<"the size of she is : "<<she.size()<<std::endl;

        /// or
        std::cout<<"size of you by using std::distance(): "<<std::distance(you.begin(),you.end())<<std::endl;


        std::list<std::string> stuff (you.size(),"stuff");
        std::cout<<stuff<<std::endl;
    }

}
/* out put */
/*
*/
