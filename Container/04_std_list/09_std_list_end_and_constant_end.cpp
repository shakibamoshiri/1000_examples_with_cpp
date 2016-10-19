/// Sequence containers : list
/// std::list
///
/// Iterators
/// 09_std::list::end_and_constant_end
/// definition in header < list >

/**
iterator end();
const_iterator end() const;
const_iterator cend() const;

Returns an iterator to the element following the last element of the container.
This element acts as a placeholder; attempting to access it results in undefined behavior.


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

        /// Note : attempting to access 'end' results in undefined behavior.
        /// So this is wrong:
        // std:cout<<you.end()<<std::endl;

        /// but this is right
        std::cout<<*--you.end()<<std::endl;
        /// or the best way: first minus minus then dereference
        std::cout<<*(--you.end())<<std::endl;

        /// okay
        std::cout<<*(--you.cend())<<std::endl;

        /// Pay attention -- (minus minus does not move iterator)
        /// an still end is in last place+1, so we have to discount it to access last element
        *(--you.end()) = "TODAY???";
        std::cout<<*--you.end()<<std::endl;

        /// this is wrong:
        // std::cout<<*(you.end()+=1)<<std::endl;

        /// and this is wrong, too
        // *(--you.cend()) = "today?";
    }

}
/* out put */
/*
*/
