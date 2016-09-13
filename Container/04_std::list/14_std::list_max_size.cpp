/// Sequence containers : list
/// std::list
///
/// Capacity
/// 14_std::list::max_size
/// definition in header < list >

/**

size_type max_size() const;

Returns the maximum number of elements the container is able to hold
due to system or library implementation limitations i.e. std::distance
(being(),end()) for the largest container.

Note:
This value is typically equal to std::numeric_limits<size_type>::max(),
and reflects the theoretical limits on the size of the container. At
runtime, the size of the container my be limited to a value smaller than
max_size by the amount of RAM available.

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
        std::list<const char*>::size_type sz = you.max_size();
        std::cout<<"before creating an array, max_size: "<<sz<<std::endl;
        char arr[400000000000000];
        sz = you.max_size();
        std::cout<<"before creating an array, max_size: "<<sz<<std::endl;

        /// not different between before and after sz
    }

}
/* out put */
/*
*/
