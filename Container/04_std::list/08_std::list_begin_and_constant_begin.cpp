/// Sequence containers : list
/// std::list
///
/// Iterators
/// 08_std::list::begin and constant_being
/// definition in header < list >

/**
iterator being();
const_iterator begin() const;
const_iterator cbegin() const;

Returns an iterator to the first element of the container.
If the container is empty, the returned iterator with be equal to end();

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

        /// A way to get iterator begin
        std::cout<<*you.begin()<<std::endl;

        /// this is correct
        *you.begin() = "woH";


        /// another way to get iterator begin
        std::list<const char*>::iterator it = you.begin();
        std::cout<<*it<<std::endl;

        /// And A way by using auto
        auto itByAuto = you.begin();
        std::cout<<*itByAuto<<std::endl;

        /// using constant iterator
        const std::list<int> ci {1,3,5,7,9};
        std::cout<<*ci.begin()<<std::endl;

        /// this is not correct because of const
        // *ci.begin() = 100;
    }

}
/* out put */
/*
*/
