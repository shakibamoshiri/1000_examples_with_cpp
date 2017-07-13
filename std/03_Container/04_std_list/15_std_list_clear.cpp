/// Sequence containers : list
/// std::list
///
/// Modifier | modify | modifying | modified | unmodified | modification
/// 15_std::list::clear
/// definition in header < list >

/**
void clear();

Removes all element form the container.
Invalidates any reference, pointers, or iterators referring to
contained element. May invalidate nay past-the-end iterator.

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
        std::cout<<"you before clearing : "<<you<<std::endl;
        you.clear();
        std::cout<<"you after clearing  : "<<you<<std::endl;

        /// because of invalidates any reference,pointer or iterator
        /// this is wrong:
        // std::cout<<*you.begin()<<std::endl;

        std::cout<<you.size()<<std::endl;

    }

}
/* out put */
/*


*/
